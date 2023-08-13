
테스트 돌려보기
2. parsing은 하나의 함수로 해서 main에 parsing(), execute()만 남긴다.
3. 아래 사항들에 대한 실행 및 예외처리
    1) Signal 파트 [08.13]
    2) 파싱부 $?와 $과 quote에 관한 예외처리
3. signal 실행부 실제로 확인하기

구현해야할 사항
0. 'Lexial를 이용하여 명령어와 아닌 것을 구분한다.'가 필요한지 생각한다.
    1) $ or not.
    2) parsing에서 처리하자.
1. $?와 $HOME에 대한 처리 [08.11]
3. 전역변수에는 그 전 명령어의 값 ($?)에 들어갈 값 담기 [08.11]
    1) echo $?를 호출하면 $?의 값을 0으로 초기화한다.
    2) SIGINT, SIGQUIT

예외처리 사항
1. <, <<만 있을 경우 에러 처리하기 [08.10]
2. 연속적인 |에 대한 예외처리 [08.12]
3. ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);를 표준 입력으로 줄 수 있는가?
    1) cat + "ctrl + '\'" > Quite: 3
    2) sleep 3 + "ctrl + '\'" > Quite: 3


새로 구현한 부분 is_file, normalize_file 테스트하기