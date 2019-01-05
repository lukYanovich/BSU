@echo off
set A_COMP_PATH=\\serv604\commons_stud\LukyanovAS\A
Chcp 65001


rem proverim zapus4en li .bat
if exist _lock.temp 
	goto _exit
else
	rename _unlock.temp _lock.tmep


if not exist %A_COMP_PATH%\new\e 
	goto _exit
if exist F: 
	net use F: /delete
net use F: %A_COMP_PATH%\new\e


rename _lock.temp _unlock.temp

:_exit
pause
exit
