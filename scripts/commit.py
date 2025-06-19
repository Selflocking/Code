import os
from pathlib import Path
import re


def commit_files() -> list[Path]:
    """
    git获取待提交的文件列表
    """
    # 执行git命令获取待提交的文件列表
    result = os.popen("git diff --cached --name-only").read()

    # 分割结果并转换为Path对象
    files = [Path(file.strip()) for file in result.splitlines() if file.strip()]

    return files


# 周赛放文件夹，题目命名：id.name.cpp
def leetcode_commit_message(path: Path) -> str:
    """
    生成leetcode题目的提交信息
    """
    # 提取文件名中的id和name
    match = re.match(r"(\d+)\.(.+)\.cpp", path.name)
    if match:
        id, name = match.groups()
        return f"leetcode: [{id}] {name}"
    else:
        return f"leetcode: {str(path).removeprefix('leetcode/').removesuffix('.cpp')}"


def get_commit_message(path: Path) -> str:
    """
    根据不同的规则生成提交信息
    """
    match path:
        case _ if path.match("leetcode/"):
            return leetcode_commit_message(path)
        case _:
            return path.name


def main():
    commit_message = ""
    files = commit_files()
    match len(files):
        case 0:
            print("没有待提交的文件")
            return
        case 1:
            commit_message = get_commit_message(files[0])
        case _:
            commit_message = "codes: multiple files\n\n"
            for file in files:
                commit_message += get_commit_message(file) + "\n"
    os.system(f"git commit -m '{commit_message}'")


if __name__ == "__main__":
    main()
