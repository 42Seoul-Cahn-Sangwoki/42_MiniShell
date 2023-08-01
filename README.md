### Rule

1. Interface.h

Base.h를 상속받아서 사용한다.
따라서 공통 분모로 사용할 함수는 Base.h에 선언한다.

Interfacce.h
- Parsing.h
- Executing.h

2. <, >

<: 입력
>: 출력

- file open 및 입력 연결
exec [연결할 fd] < [read할 자원]

- 출력 연결
exec [연결할 fd] > [write할 자원]

echo 111 >&3 # 출력 1 -> &3으로 변경
echo 111 > outfile # 연결하지 않고 출력으로 연결할 시 (open -> write -> close)

3. here document <<

- 임시 파일을 생성 후 STDIN으로 입력한다. -> 출력해야 닫힌다.
- [출력할 fd]<< END # 해당 fd에 값이 적힌다.
- <<\EOF -s [매개변수] # 임시파일에 -s로 매개변수를 넘길 수 있다.

cat << END

<< END cat

3<< END cat /dev/fd/3
> hello
> END
hello

- 환경변수 처리

4. Singal

- 


5. '', "", 홀수, 짝수 구분