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
    for j = 1:col
        if IsSymbol(map(i, j))
            num = CaclRatio(smap, i, j);
            if num ~=0
                fprintf("find symbol at (%d, %d), num: %d\n", i, j, num);
            end
            answer = answer + num;
        end
    end
end

fprintf("answer: %d\n", answer);

function [num] = CaclRatio(smap, i,j)
    num = 0;
    around = IsNum(smap(i-1:i+1,j-1:j+1));
    if sum(around(:)) < 2 || sum(around(:)) > 6
        return;
    end

    numcnt = 0;
    num = 1;
    if around(2,1)
        numcnt = numcnt + 1;
        num = num * GetNum(smap,i,j-1);
    end

    if around(2,3)
        numcnt = numcnt + 1;
        num = num * GetNum(smap,i,j+1);
    end

    switch sum(around(1,:))
        case 3
            numcnt = numcnt + 1;
            num = num * GetNum(smap,i-1,j);
        case 2
            if around(1,2)
                numcnt = numcnt + 1;
                num = num * GetNum(smap,i-1,j);
            else
                numcnt = numcnt + 2;
                num = num * GetNum(smap,i-1,j-1) * GetNum(smap,i-1,j+1);
            end
        case 1
            if around(1,1)
                numcnt = numcnt + 1;
                num = num * GetNum(smap,i-1,j-1);
            elseif around(1,3)
                numcnt = numcnt + 1;
                num = num * GetNum(smap,i-1,j+1);
            else
                numcnt = numcnt + 1;
                num = num * GetNum(smap,i-1,j);
            end
    end

    switch sum(around(3,:))
        case 3
            numcnt = numcnt + 1;
            num = num * GetNum(smap,i+1,j);
        case 2
            if around(3,2)
                numcnt = numcnt + 1;
                num = num * GetNum(smap,i+1,j);
            else
                numcnt = numcnt + 2;
                num = num * GetNum(smap,i+1,j-1) * GetNum(smap,i+1,j+1);
            end
        case 1
            if around(3,1)
                numcnt = numcnt + 1;
                num = num * GetNum(smap,i+1,j-1);
            elseif around(3,3)
                numcnt = numcnt + 1;
                num = num * GetNum(smap,i+1,j+1);
            else
                numcnt = numcnt + 1;
                num = num * GetNum(smap,i+1,j);
            end
    end

    if numcnt ~=2
        num = 0;
    end
end

function [num] = GetNum(smap,i,j)
    while(IsNum(smap(i,j)))
        j = j-1;
    end
    j = j+1;
    num = 0;
    while(IsNum(smap(i,j)))
        num = num*10 + str2num(smap(i,j));
        j = j+1;
    end
end

% 读取文件，返回一个二维字符数组
function [map] = LoadFile(filepath)
    data = fileread(filepath);
    data = strsplit(data, '\n');
    map = char(data(1:end));
end

function [result] = IsSymbol(c)
    result = zeros(size(c, 1), size(c, 2));
    row = size(c, 1);
    col = size(c, 2);
    for i = 1:row
        for j = 1:col
            if ~IsNum(c(i,j)) && c(i,j) ~= '.'
                result(i,j) = 1;
            end
        end
    end
end

function [result] = IsNum(c)
    result = zeros(size(c, 1), size(c, 2));
    row = size(c, 1);
    col = size(c, 2);
    for i = 1:row
        for j = 1:col
            if c(i,j) >='0' && c(i,j) <= '9'
                result(i,j) = 1;
            end
        end
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
