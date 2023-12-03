clear;
% filepath = "example.txt";
filepath = "input.txt";
map = LoadFile(filepath);
row = size(map, 1);
col = size(map, 2);
% 越界处理
smap = FuncFactory(map);

answer = 0;

for i = 1:row
    num = 0;
    for j = 1:col
        if(IsNum(map(i, j)))
            num = num * 10 + str2double(map(i, j));
        else
            if num ~= 0
                numlen = size(num2str(num), 2);
                if Check(smap, i, j-numlen, numlen)
                    answer = answer + num;
                    fprintf("find %d at (%d, %d)\n", num, i, j-numlen);
                end
                num = 0;
            end
        end
    end
    if num ~= 0
        numlen = size(num2str(num), 2);
        if Check(smap, i, col+1-numlen, numlen)
            answer = answer + num;
            fprintf("find %d at (%d, %d)\n", num, i, j-numlen);
        end
        num = 0;
    end
end

fprintf("answer: %d\n", answer);

% 读取文件，返回一个二维字符数组
function [map] = LoadFile(filepath)
    data = fileread(filepath);
    data = strsplit(data, '\n');
    map = char(data(1:end));
end

function [result] = Check(smap, x, y, numlen)
    result = 0;

    if IsSymbol(smap(x-1:x+1, y-1))
        result = 1;
        return;
    end

    if IsSymbol(smap(x-1:2:x+1,y:y+numlen))
        result = 1;
        return;
    end

    if IsSymbol(smap(x-1:x+1,y+numlen))
        result = 1;
        return;
    end
end

function [result] = IsSymbol(c)
    result = 0;
    row = size(c, 1);
    col = size(c, 2);
    for i = 1:row
        for j = 1:col
            if ~IsNum(c(i,j)) && c(i,j) ~= '.'
                result = 1;
                return;
            end
        end
    end
end

function [result] = IsNum(c)
    result = 0;
    if c <= '9' && c >= '0'
        result = 1;
    end
end

function func = FuncFactory(map)
    data = map;
    row = size(data, 1);
    col = size(data, 2);
    function val = lamdba(x, y)
        % 初始化输出为与x和y相同大小的字符矩阵
        val = repmat('.', length(x), length(y));
        
        % 对于x和y中的每个值对，检查它们是否在map的范围内
        for i = 1:length(x)
            for j = 1:length(y)
                if x(i) > 0 && y(j) > 0 && x(i) <= row && y(j) <= col
                    val(i, j) = data(x(i), y(j));
                end
            end
        end
    end

    func = @lamdba;
end
