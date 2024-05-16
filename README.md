# minishell
### 구현 목표

Bash-like shell 구현하기

참고 문헌: [Bash Reference Manual](https://www.gnu.org/software/bash/manual/html_node/index.html)

### 구현 
1. Searching for Commands in the History
2. 상대 경로, 절대 경로를 기반으로 검색하고 실행해야 한다.
3. built-in 함수: echo -n, cd, pwd, export, unset, env, exit, redirections, pipelines 등
4. $?을 검색했을 때, 최근 실행된 프로세스의 종료 상태가 출력된다.
5. shell에서 SIGINT(ctrl-c), EOF(ctrl-D), SIGQUIT(ctrl-\\)가 작동되어야 한다.

# 실행 내용
```
make
```

```
./minishell
```

make로 Makefile을 실행하여 C언어 파일을 컴파일하고, minishell을 실행한다.

minishell 내부에서 Bash 명령어를 실행한다.

### redirections

1. Redirecting Input
2. Redirecting Output
3. Here Documents

아래의 그림은, Redirecting ouput과 Here Documents 명령어 실행 화면 입니다.

<img width="537" alt="redirections" src="https://github.com/42Seoul-Cahn-Sangwoki/42_MiniShell/assets/65798779/b37049aa-55a4-4aba-acd5-9872ce3c036f">

Redirecting output과 Redirecting input 명령어 실행 화면 입니다.

<img width="248" alt="redirection2" src="https://github.com/42Seoul-Cahn-Sangwoki/42_MiniShell/assets/65798779/f0b4213f-94f9-417c-917e-af93c3def893">

### pipelines
```
sleep 5 | sleep 3
```
아래의 그림을 통해 pipelines를 통해 2개의 프로세스가 병렬적으로 실행되었다는 것을 알 수 있습니다.

<img width="466" alt="pipelines" src="https://github.com/42Seoul-Cahn-Sangwoki/42_MiniShell/assets/65798779/d83da366-3b59-45d3-a394-081c343bdf7b">


### echo, cd, pwd, ls

echo, cd, pwd, ls의 명령어가 정확히 동작하는 것을 알 수 있습니다.

<img width="448" alt="Screen Shot 2024-05-16 at 5 36 35 PM" src="https://github.com/42Seoul-Cahn-Sangwoki/42_MiniShell/assets/65798779/69eaf5d3-47d0-44b0-814f-d008747e6adf">


### export, unset, env

export를 통해 환경 변수를 등록하고, unset을 통해 등록된 변수를 해제합니다.

이를 env 명령어로 확인할 수 있습니다.

export로 환경 변수를 등록합니다.

<img width="567" alt="Screen Shot 2024-05-16 at 5 42 42 PM" src="https://github.com/42Seoul-Cahn-Sangwoki/42_MiniShell/assets/65798779/b4c7e2d0-1d40-4c27-a92e-5da0624ea755">

unset으로 등록된 환경 변수를 제거합니다.

<img width="483" alt="Screen Shot 2024-05-16 at 5 43 17 PM" src="https://github.com/42Seoul-Cahn-Sangwoki/42_MiniShell/assets/65798779/13891650-07e8-4093-bc62-86ba8d7d81f5">

### $?과 SIGNAL

$?을 통해 종료 상태를 확인할 수 있습니다.

<img width="279" alt="Screen Shot 2024-05-16 at 5 46 59 PM" src="https://github.com/42Seoul-Cahn-Sangwoki/42_MiniShell/assets/65798779/a8fc782c-dacf-4bf3-b3c2-65d1807e6c3d">

