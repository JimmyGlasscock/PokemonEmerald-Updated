.set LOCALID_SUDOWOODO, 14

BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "This is the BATTLE TOWER!\n"
	.string "Keep the win streak as the toughest\l"
	.string "TRAINER!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "This is the BATTLE PALACE!\n"
	.string "Keep your eyes on POKéMON battles!$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "This is the BATTLE ARENA!\n"
	.string "Let the toughest teams gather!$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "This is the BATTLE PYRAMID!\n"
	.string "Advance through the Battle Quest!$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "BATTLE FRONTIER RANKING HALL\n"
	.string "Set your sights on new records!$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "BATTLE POINT EXCHANGE SERVICE CORNER\n"
	.string "Exchange your Battle Points!$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Wow!\n"
	.string "It's huge!\p"
	.string "The BATTLE TOWER feels special.\n"
	.string "It's different from the others.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "My grand ambition is to conquer both\n"
	.string "the BATTLE FRONTIER and the POKéMON\l"
	.string "LEAGUE.\p"
	.string "And if my dream comes true…\p"
	.string "I… I'm going to ask MIMI next door\n"
	.string "if she will be friends with me!$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "The BATTLE PYRAMID's too harsh!\n"
	.string "I just can't make it to the top!\p"
	.string "Since I'm out of options, maybe I can\n"
	.string "climb the outside…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "I thrive in darkness…\n"
	.string "Yes… What is worthy of me?\l"
	.string "None other than the BATTLE PYRAMID…\p"
	.string "What say you to wandering in darkness\n"
	.string "and in utter and total desperation?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "I didn't sleep for a week, but then\n"
	.string "I put together the ultimate team!\p"
	.string "I can't see myself losing, no joke.\n"
	.string "We're storming the BATTLE ARENA!$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "Did SCOTT bring you here, too?\n"
	.string "What is it with that guy?\p"
	.string "It sounds like he really does know\n"
	.string "how to spot talented TRAINERS, but…\p"
	.string "I've never seen him battling in person\n"
	.string "ever.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG!\n"
	.string "I believe in you, little buddy!\p"
	.string "I'll make my little ZIGG any favorite\n"
	.string "tasty treats you like if you win!$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON looks vacant…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "People call me a busybody,\n"
	.string "but I can't help it.\p"
	.string "Your hat's on crooked!\n"
	.string "Oh, no, trash on the ground!\l"
	.string "Oops, it's almost dinnertime!\p"
	.string "I don't know if I can stand to just\n"
	.string "watch at the BATTLE PALACE…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "I may not look that impressive now,\n"
	.string "but I once beat a GYM LEADER.\p"
	.string "Who knows, maybe I should give it\n"
	.string "another shot at glory.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "I'm fast on my BIKE, and that goes for\n"
	.string "the way I battle, too.\p"
	.string "I win matches in the blink of\n"
	.string "an eye!$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "I'm better than my daddy\n"
	.string "at POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Go on, my baby sweetie!\n"
	.string "Go rack up some wins for Daddy!\p"
	.string "You're just like your mother,\n"
	.string "so you'll be dominating!$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "It wasn't easy getting here,\n"
	.string "but I'd heard about this knockout\l"
	.string "pretty girl at the BATTLE ARENA.\p"
	.string "Instead of her, do you know what\n"
	.string "I found?\p"
	.string "A whole teeming mob of sweaty,\n"
	.string "stinky, and primitive martial artists!$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "I sometimes see this really important-\n"
	.string "looking old man going in there.\p"
	.string "He has these really awesome POKéMON.\n"
	.string "He seems really nice, though.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Do you know it?\n"
	.string "The legend of the BATTLE PYRAMID?\p"
	.string "When there comes a confident TRAINER\n"
	.string "reaching for the golden pinnacle,\l"
	.string "there shall appear a man among men.\p"
	.string "Don't know that legend?\n"
	.string "Well, of course not!\l"
	.string "I just made it up!\p"
	.string "What's it supposed to mean?\n"
	.string "That, my friend, I can't say!$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Man! Oh man!\n"
	.string "I've never lost once before!\p"
	.string "But I got wiped out with no saving\n"
	.string "grace at all!\p"
	.string "And then I'm told I don't have any\n"
	.string "talent?! Man!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "This guy ran into a horribly tough\n"
	.string "TRAINER while he was on the BATTLE\l"
	.string "TOWER challenge.\p"
	.string "Now look at him…\p"
	.string "You need to be cautious if you ever\n"
	.string "decide to go to the BATTLE TOWER.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Yes!\n"
	.string "I've finally got enough Battle Points!\p"
	.string "I guess I'll trade for another giant\n"
	.string "plush DOLL!$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Oh, yeah, okay!\n"
	.string "So this is the RANKING HALL!\p"
	.string "I'd like to go down in history as\n"
	.string "a super champ and have my name\l"
	.string "recorded here for posterity.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "With you by my side, I can do anything.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ooh, darling, you are so wonderful!\p"
	.string "Ooh, I just can't wait anymore!\p"
	.string "Let's go to a MULTI BATTLE ROOM\n"
	.string "right this instant!\p"
	.string "If we get together in the BATTLE SALON,\n"
	.string "the power of our love will overcome\l"
	.string "everyone we meet.\p"
	.string "Why, before us, darling, everything\n"
	.string "will topple like dominoes!$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "The BATTLE FRONTIER isn't exclusively\n"
	.string "for tough TRAINERS.\p"
	.string "Many people with special abilities\n"
	.string "have been invited, it seems.\p"
	.string "That man SCOTT…\p"
	.string "He may have built this place to serve\n"
	.string "a bigger objective…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Excuse me, young one.\n"
	.string "Have you good eyesight?\p"
	.string "There is an odd tree past here, and to\n"
	.string "my tired eyes it seems to wiggle.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Excuse me, young one.\n"
	.string "Have you a good memory?\p"
	.string "I have this feeling there once was\n"
	.string "an odd tree past here.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "I…\n"
	.string "I saw it!\p"
	.string "There was a sticky sort of a POKéMON\n"
	.string "with a long tail up ahead!\p"
	.string "It was hiding under a boulder, and\n"
	.string "it kept staring at me!$"

BattleFrontier_OutsideEast_EventScript_StarterGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OTHER_STARTERS, BattleFrontier_OutsideEast_EventScript_AlreadyReceivedStarters
	msgbox BattleFrontier_OutsideEast_Text_StarterGiverIntro, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_OTHER_STARTERS
	copyvar VAR_0x8005, VAR_STARTER_MON
	goto_if_eq VAR_0x8005, 0, BattleFrontier_OutsideEast_EventScript_GiveTorchicAndMudkip
	goto_if_eq VAR_0x8005, 1, BattleFrontier_OutsideEast_EventScript_GiveTreeckoAndMudkip
	goto_if_eq VAR_0x8005, 2, BattleFrontier_OutsideEast_EventScript_GiveTreeckoAndTorchic
	release
	end

BattleFrontier_OutsideEast_EventScript_GiveTreeckoAndTorchic::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TREECKO
	givemon SPECIES_TREECKO, 10
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BattleFrontier_OutsideEast_EventScript_ReceiveTreeckoParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BattleFrontier_OutsideEast_EventScript_ReceiveTreeckoPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

BattleFrontier_OutsideEast_EventScript_ReceiveTreeckoParty::
	call BattleFrontier_OutsideEast_EventScript_ReceivedTreeckoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_GiveTorchicAfterTreecko
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_OutsideEast_EventScript_GiveTorchicAfterTreecko
	end

BattleFrontier_OutsideEast_EventScript_ReceiveTreeckoPC::
	call BattleFrontier_OutsideEast_EventScript_ReceivedTreeckoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_TransferTreeckoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_OutsideEast_EventScript_TransferTreeckoToPC
	end

BattleFrontier_OutsideEast_EventScript_TransferTreeckoToPC::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_OutsideEast_EventScript_GiveTorchicAfterTreecko
	end

BattleFrontier_OutsideEast_EventScript_ReceivedTreeckoFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_TREECKO
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_OutsideEast_Text_ReceivedMonFromStarterGiver
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	return

BattleFrontier_OutsideEast_EventScript_GiveTorchicAfterTreecko::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORCHIC
	givemon SPECIES_TORCHIC, 10
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BattleFrontier_OutsideEast_EventScript_ReceiveTorchicParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BattleFrontier_OutsideEast_EventScript_ReceiveTorchicPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

BattleFrontier_OutsideEast_EventScript_ReceiveTorchicParty::
	call BattleFrontier_OutsideEast_EventScript_ReceivedTorchicFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_FinishReceivingStarters
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_OutsideEast_EventScript_FinishReceivingStarters
	end

BattleFrontier_OutsideEast_EventScript_ReceiveTorchicPC::
	call BattleFrontier_OutsideEast_EventScript_ReceivedTorchicFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_TransferTorchicToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_OutsideEast_EventScript_TransferTorchicToPC
	end

BattleFrontier_OutsideEast_EventScript_TransferTorchicToPC::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_OutsideEast_EventScript_FinishReceivingStarters
	end

BattleFrontier_OutsideEast_EventScript_ReceivedTorchicFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_TORCHIC
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_OutsideEast_Text_ReceivedMonFromStarterGiver
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	return

BattleFrontier_OutsideEast_EventScript_GiveTreeckoAndMudkip::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TREECKO
	givemon SPECIES_TREECKO, 10
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BattleFrontier_OutsideEast_EventScript_ReceiveTreeckoParty2
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BattleFrontier_OutsideEast_EventScript_ReceiveTreeckoPC2
	goto Common_EventScript_NoMoreRoomForPokemon
	end

BattleFrontier_OutsideEast_EventScript_ReceiveTreeckoParty2::
	call BattleFrontier_OutsideEast_EventScript_ReceivedTreeckoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_GiveMudkipAfterTreecko
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_OutsideEast_EventScript_GiveMudkipAfterTreecko
	end

BattleFrontier_OutsideEast_EventScript_ReceiveTreeckoPC2::
	call BattleFrontier_OutsideEast_EventScript_ReceivedTreeckoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_TransferTreeckoToPC2
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_OutsideEast_EventScript_TransferTreeckoToPC2
	end

BattleFrontier_OutsideEast_EventScript_TransferTreeckoToPC2::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_OutsideEast_EventScript_GiveMudkipAfterTreecko
	end

BattleFrontier_OutsideEast_EventScript_GiveMudkipAfterTreecko::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MUDKIP
	givemon SPECIES_MUDKIP, 10
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BattleFrontier_OutsideEast_EventScript_ReceiveMudkipParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BattleFrontier_OutsideEast_EventScript_ReceiveMudkipPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

BattleFrontier_OutsideEast_EventScript_ReceiveMudkipParty::
	call BattleFrontier_OutsideEast_EventScript_ReceivedMudkipFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_FinishReceivingStarters
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_OutsideEast_EventScript_FinishReceivingStarters
	end

BattleFrontier_OutsideEast_EventScript_ReceiveMudkipPC::
	call BattleFrontier_OutsideEast_EventScript_ReceivedMudkipFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_TransferMudkipToPC
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_OutsideEast_EventScript_TransferMudkipToPC
	end

BattleFrontier_OutsideEast_EventScript_TransferMudkipToPC::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_OutsideEast_EventScript_FinishReceivingStarters
	end

BattleFrontier_OutsideEast_EventScript_ReceivedMudkipFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_MUDKIP
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_OutsideEast_Text_ReceivedMonFromStarterGiver
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	return

BattleFrontier_OutsideEast_EventScript_GiveTorchicAndMudkip::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TORCHIC
	givemon SPECIES_TORCHIC, 10
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BattleFrontier_OutsideEast_EventScript_ReceiveTorchicParty2
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BattleFrontier_OutsideEast_EventScript_ReceiveTorchicPC2
	goto Common_EventScript_NoMoreRoomForPokemon
	end

BattleFrontier_OutsideEast_EventScript_ReceiveTorchicParty2::
	call BattleFrontier_OutsideEast_EventScript_ReceivedTorchicFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_GiveMudkipAfterTorchic
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_OutsideEast_EventScript_GiveMudkipAfterTorchic
	end

BattleFrontier_OutsideEast_EventScript_ReceiveTorchicPC2::
	call BattleFrontier_OutsideEast_EventScript_ReceivedTorchicFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_TransferTorchicToPC2
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_OutsideEast_EventScript_TransferTorchicToPC2
	end

BattleFrontier_OutsideEast_EventScript_TransferTorchicToPC2::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_OutsideEast_EventScript_GiveMudkipAfterTorchic
	end

BattleFrontier_OutsideEast_EventScript_GiveMudkipAfterTorchic::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MUDKIP
	givemon SPECIES_MUDKIP, 10
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, BattleFrontier_OutsideEast_EventScript_ReceiveMudkipParty2
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, BattleFrontier_OutsideEast_EventScript_ReceiveMudkipPC2
	goto Common_EventScript_NoMoreRoomForPokemon
	end

BattleFrontier_OutsideEast_EventScript_ReceiveMudkipParty2::
	call BattleFrontier_OutsideEast_EventScript_ReceivedMudkipFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_FinishReceivingStarters
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto BattleFrontier_OutsideEast_EventScript_FinishReceivingStarters
	end

BattleFrontier_OutsideEast_EventScript_ReceiveMudkipPC2::
	call BattleFrontier_OutsideEast_EventScript_ReceivedMudkipFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideEast_EventScript_TransferMudkipToPC2
	call Common_EventScript_NameReceivedBoxMon
	goto BattleFrontier_OutsideEast_EventScript_TransferMudkipToPC2
	end

BattleFrontier_OutsideEast_EventScript_TransferMudkipToPC2::
	call Common_EventScript_TransferredToPC
	goto BattleFrontier_OutsideEast_EventScript_FinishReceivingStarters
	end

BattleFrontier_OutsideEast_EventScript_FinishReceivingStarters::
	msgbox BattleFrontier_OutsideEast_Text_ReceivedBothStarters, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_AlreadyReceivedStarters::
	msgbox BattleFrontier_OutsideEast_Text_AlreadyReceivedStarters, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_Text_StarterGiverIntro:
	.string "Hey Hey!\p"
	.string "I'm the starter guy!\p"
	.string "You look like you could use\n"
	.string "some POKéMON!$"

BattleFrontier_OutsideEast_Text_ReceivedMonFromStarterGiver:
	.string "{PLAYER} received {STR_VAR_2} from\n"
	.string "the starter guy!$"

BattleFrontier_OutsideEast_Text_ReceivedBothStarters:
	.string "Take good care of them!$"

BattleFrontier_OutsideEast_Text_AlreadyReceivedStarters:
	.string "Take good care of them!$"
