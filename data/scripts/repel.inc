EventScript_RepelWoreOff::
	lockall
	checkitem ITEM_MAX_REPEL, 1
	goto_if_ne VAR_RESULT, FALSE, EventScript_RepelWoreOff_CheckMaxRepel
	checkitem ITEM_SUPER_REPEL, 1
	goto_if_ne VAR_RESULT, FALSE, EventScript_RepelWoreOff_CheckSuperRepel
	checkitem ITEM_REPEL, 1
	goto_if_ne VAR_RESULT, FALSE, EventScript_RepelWoreOff_CheckRepel
	goto EventScript_RepelWoreOff_NoRepels

EventScript_RepelWoreOff_CheckMaxRepel::
	msgbox Text_RepelWoreOff_UseAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RepelWoreOff_End
	removeitem ITEM_MAX_REPEL, 1
	setvar VAR_REPEL_STEP_COUNT, 250
	playse SE_REPEL
	message Text_RepelWoreOff_UsedMaxRepel
	waitmessage
	delay 60
	closemessage
	goto EventScript_RepelWoreOff_End

EventScript_RepelWoreOff_CheckSuperRepel::
	msgbox Text_RepelWoreOff_UseAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RepelWoreOff_End
	removeitem ITEM_SUPER_REPEL, 1
	setvar VAR_REPEL_STEP_COUNT, 200
	playse SE_REPEL
	message Text_RepelWoreOff_UsedSuperRepel
	waitmessage
	delay 60
	closemessage
	goto EventScript_RepelWoreOff_End

EventScript_RepelWoreOff_CheckRepel::
	msgbox Text_RepelWoreOff_UseAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_RepelWoreOff_End
	removeitem ITEM_REPEL, 1
	setvar VAR_REPEL_STEP_COUNT, 100
	playse SE_REPEL
	message Text_RepelWoreOff_UsedRepel
	waitmessage
	delay 60
	closemessage
	goto EventScript_RepelWoreOff_End

EventScript_RepelWoreOff_NoRepels::
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	goto EventScript_RepelWoreOff_End

EventScript_RepelWoreOff_End::
	releaseall
	end

Text_RepelWoreOff:
	.string "REPEL's effect wore off…$"

Text_RepelWoreOff_UseAnother:
	.string "REPEL's effect wore off…\nuse another?$"

Text_RepelWoreOff_UsedMaxRepel:
	.string "{PLAYER} used the\nMAX REPEL.\pWild POKéMON will be repelled.$"

Text_RepelWoreOff_UsedSuperRepel:
	.string "{PLAYER} used the\nSUPER REPEL.\pWild POKéMON will be repelled.$"

Text_RepelWoreOff_UsedRepel:
	.string "{PLAYER} used the\nREPEL.\pWild POKéMON will be repelled.$"
