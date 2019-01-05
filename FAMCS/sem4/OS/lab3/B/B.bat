@echo off
set B_COMP_PATH=C:\Projects\FAMCS\sem4\OS\lab3\B
Chcp 65001


rem proverim zapus4en li .bat
if exist _lock.temp 
	goto _exit
else
	rename _unlock.temp _lock.tmep


rem ************************************************************************************
rem xcopy — copy dir
	rem /Y - ne sprashivat' perezapis'
	rem /S - vse vlogennye
	rem /H - skrytye i sistemnye
	rem /C - ignor errers
rem rmdir — remove dir
	rem /Q — ne sprashivat
	rem /S — vse vlogennye

rem pri copirovanii dlia udobstva
rem tania - 1
rem galia - 2
rem masha - 3
rem ************************************************************************************


if exist "%B_COMP_PATH%\galia\last1" (

	rmdir "%B_COMP_PATH%\masha\prev1" /Q /S
	xcopy "%B_COMP_PATH%\galia\last1" "%B_COMP_PATH%\masha\prev1" /H /Y /C /S
	rmdir "%B_COMP_PATH%\galia\last1" /Q /S
)

xcopy "%B_COMP_PATH%\tania\d" "%B_COMP_PATH%\galia\last1\d" /Y /C


if exist "%B_COMP_PATH%\masha\last2" (

	rmdir "%B_COMP_PATH%\tania\prev2" /Q /S
	xcopy "%B_COMP_PATH%\masha\last2" "%B_COMP_PATH%\tania\prev2" /H /Y /C /S
	rmdir "%B_COMP_PATH%\tania\last2" /Q /S
)

xcopy "%B_COMP_PATH%\galia\c\Мои документы" "%B_COMP_PATH%\masha\last2\c\Мои документы" /H /Y /C /S
xcopy "%B_COMP_PATH%\galia\d" "%B_COMP_PATH%\masha\last2\d" /Y /C


if exist "%B_COMP_PATH%\tania\last3" (

	rmdir "%B_COMP_PATH%\galia\prev3" /Q /S
	xcopy "%B_COMP_PATH%\tania\last3" "%B_COMP_PATH%\galia\prev3" /H /Y /C /S
	rmdir "%B_COMP_PATH%\tania\last3" /Q /S
)

xcopy "%B_COMP_PATH%\masha\d\Письма" "%B_COMP_PATH%\tania\last3\d\Письма" /Y /C
xcopy "%B_COMP_PATH%\masha\d\Письма\Банк" "%B_COMP_PATH%\tania\last3\d\Письма\Банк" /Y /C
xcopy "%B_COMP_PATH%\masha\d\Письма\ИМНС" "%B_COMP_PATH%\tania\last3\d\Письма\ИМНС" /Y /C
xcopy "%B_COMP_PATH%\masha\e\diplom" "%B_COMP_PATH%\tania\last3\e\diplom" /H /Y /C /S


rename _lock.temp _unlock.temp

:_exit
pause
exit
