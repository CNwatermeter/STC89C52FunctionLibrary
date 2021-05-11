首先cd到目标目录

git init 初始化目录

git add . 选定该目录的所有文件加入本地暂存区，如果需要添加单独的文件就把.换成单独的文件的名称

git status 查看当前状态，该命令将会将工作空间中的版本与暂存区的版本进行对比

git commit -m “项目注释”

git remote add origin SSH 将本地历史区中的文件添加到Github服务的暂存区中

SSH git@github.com:CNwatermeter/STC89C52FunctionLibrary.git

git pull origin master 将GitHub上的文件拉下来，每次提交都需要进行此步骤，这是为了防止文件的冲突

git pull origin master --allow-unrelated-histories 如果上述指令报错则执行本指令

git push origin master 正式向GitHub提交代码