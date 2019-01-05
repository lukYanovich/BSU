@echo off
set A_COMP_PATH=\\serv604\commons_stud\LukyanovAS\A
Chcp 65001


rem proverim zapus4en li .bat
if exist _lock.temp 
	goto _exit
else
	rename _unlock.temp _lock.tmep


if not exist %A_COMP_PATH%\old\e 
	goto m
if exist K: 
	net use K: /delete
net use K: %A_COMP_PATH%\old\e

:m
if not exist %A_COMP_PATH%\old\c 
	goto _exit
if exist R: 
	net use R: /delete
net use R: %A_COMP_PATH%\old\c


rename _lock.temp _unlock.temp

:_exit
pause
exit
