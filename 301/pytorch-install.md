# [Pytorch INstall](https://pytorch.org/get-started/locally/)

## with Windows
### the easies way: install under Anaconda
- **以管理员身份打开** 'anaconda pwoershell promplt', enter the windows (base) environment (点击windows logo，在应用中找到Anaconda Powershell Promplt, 右键，以管理员身份打开)
- 在base环境中输入 `conda install pytorch torchvision torchaudio cpuonly -c pytorch`

### [在jupyter lab中验证安装](https://pytorch.org/get-started/locally/#windows-verification)
- 继续在八色环境中cd你的代码目录
- jupyter lab
- create a new jupygter notebook and enter python code:
```python
import torch
x = torch.rand(5, 3)
print(x)
```
- run it, and you should returned with:
```python
tensor([[0.3380, 0.3845, 0.3217],
        [0.8337, 0.9050, 0.2650],
        [0.2979, 0.7141, 0.9069],
        [0.1449, 0.1132, 0.1375],
        [0.4675, 0.3947, 0.1426]])
```

### 在vs code中运行：
- 在代码目录中输入命令：`code .`
- 确认python extension已安装
- `ctrl+shift+p`找到`python select interpretor`, 选择anaconda base的python(一般安装在`c:\programedata\ananconda3\python.exe`)
- 建立一个`test.py`，输入以上验证代码
- 进入vs code的terminal, 在代码目录里输入python text.py，看看是否能正常返回内容。