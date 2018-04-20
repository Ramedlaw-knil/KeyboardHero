
;;; gcc for m6809 : Feb 15 2016 21:40:10
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mint8
	.module	main.c
	.area .text
	.globl _DrawVecList
_DrawVecList:
	leas	-7,s
	stx	2,s
	ldx	2,s
	ldx	1,x
	ldx	,x
	stx	5,s
	ldx	5,s
	jsr	__Moveto_dd
	ldb	#1
	stb	4,s
	bra	L2
L3:
	ldx	2,s
	ldx	1,x
	ldb	4,s
	clra		;zero_extendqihi: R:b -> R:d
	std	,s
	ldd	,s
	aslb
	rola
	leax	d,x
	jsr	_Draw
	inc	4,s
L2:
	ldb	[2,s]
	cmpb	4,s	;cmpqi:
	bhi	L3
	leas	7,s
	rts
_Draw:
	leas	-5,s
	stx	1,s
	ldx	1,s
	ldb	1,x
	stb	,s
	ldb	[1,s]
	stb	4,s
	ldb	,s
	stb	3,s
	ldb	4,s
	stb	,-s
	ldb	4,s
	jsr	__Draw_Line_d
	leas	1,s
	leas	5,s
	rts
	.globl _channel1Counter
	.area .data
_channel1Counter:
	.byte	0	;skip space
	.globl _channel2Counter
_channel2Counter:
	.byte	0	;skip space
	.globl _channel3Counter
_channel3Counter:
	.byte	0	;skip space
	.area .text
	.globl _play_tune
_play_tune:
	leas	-16,s
	stb	6,s
	stx	4,s
	ldb	6,s
	aslb
	stb	7,s
	ldd	4,s
	stb	8,s	;movlsbqihi: R:d -> 8,s
	ldb	7,s
	inc	7,s
	stb	11,s
	ldb	8,s
	stb	10,s
	ldb	11,s
	stb	,-s
	ldb	11,s
	jsr	__Sound_Byte
	leas	1,s
	ldd	4,s
	tfr	a,b
	clra		;zero_extendqihi: R:b -> R:d
	stb	9,s	;movlsbqihi: R:d -> 9,s
	ldb	7,s
	stb	13,s
	ldb	9,s
	stb	12,s
	ldb	13,s
	stb	,-s
	ldb	13,s
	jsr	__Sound_Byte
	leas	1,s
	clr	2,s
	ldx	4,s
	cmpx	#0
	beq	L8
	ldb	#1
	stb	2,s
L8:
	ldb	2,s
	lda	18,s	;umulqihi3
	mul
	std	,s
	ldd	,s
	stb	3,s	;movlsbqihi: R:d -> 3,s
	ldb	6,s
	addb	#8
	stb	15,s
	ldb	3,s
	stb	14,s
	ldb	15,s
	stb	,-s
	ldb	15,s
	jsr	__Sound_Byte
	leas	1,s
	ldb	#7
	stb	,-s
	ldb	#56
	jsr	__Sound_Byte
	leas	1,s
	leas	16,s
	rts
	.globl _vectorsKey
_vectorsKey:
	.byte	-10
	.byte	-15
	.byte	20
	.byte	0
	.byte	0
	.byte	30
	.byte	-20
	.byte	0
	.byte	0
	.byte	-30
	.globl _vectorsNote
_vectorsNote:
	.byte	-10
	.byte	-10
	.byte	20
	.byte	0
	.byte	0
	.byte	20
	.byte	-20
	.byte	0
	.byte	0
	.byte	-20
	.globl _keyVecList
_keyVecList:
	.byte	5
	.word	_vectorsKey
	.globl _noteVecList
_noteVecList:
	.byte	5
	.word	_vectorsNote
	.globl _Divider
_Divider:
	.byte	-50
	.globl _yKeyPos
_yKeyPos:
	.byte	-118
	.globl _xKeyPos
_xKeyPos:
	.byte	100
	.globl _toggle
	.area .data
_toggle:
	.byte	-50
	.globl _FirstRow
	.area .text
_FirstRow:
	.byte	-50
	.globl _SecondRow
_SecondRow:
	.byte	0	;skip space
	.globl _ThirdRow
_ThirdRow:
	.byte	50
	.globl _FourthRow
_FourthRow:
	.byte	100
	.globl _frequencys1
_frequencys1:
	.word	568
	.word	477
	.word	378
	.word	477
	.word	568
	.word	477
	.word	378
	.word	477
	.word	568
	.word	477
	.word	378
	.word	477
	.word	568
	.word	477
	.word	378
	.word	477
	.globl _durations1
_durations1:
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.globl _frequencys2
_frequencys2:
	.word	477
	.word	378
	.word	284
	.word	378
	.word	477
	.word	378
	.word	284
	.word	378
	.word	477
	.word	378
	.word	284
	.word	378
	.word	477
	.word	378
	.word	284
	.word	378
	.globl _durations2
_durations2:
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.byte	18
	.globl _frequencys3
_frequencys3:
	.word	119
	.word	142
	.word	94
	.word	142
	.word	94
	.word	89
	.word	142
	.word	106
	.word	239
	.word	106
	.word	94
	.word	106
	.word	63
	.word	89
	.word	94
	.word	150
	.word	119
	.word	142
	.word	94
	.word	142
	.word	94
	.word	89
	.word	142
	.word	106
	.word	239
	.word	106
	.word	94
	.word	106
	.word	63
	.word	89
	.word	94
	.word	150
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.globl _durations3
_durations3:
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.byte	9
	.globl __Rhythm1
	.area .data
__Rhythm1:
	.word	_frequencys1
	.word	_durations1
	.word	0	;skip space 4
	.word	0	;skip space 2
	.globl __Rhythm2
__Rhythm2:
	.word	_frequencys2
	.word	_durations2
	.word	0	;skip space 4
	.word	0	;skip space 2
	.globl __Lead
__Lead:
	.word	_frequencys3
	.word	_durations3
	.word	0	;skip space 4
	.word	0	;skip space 2
	.globl _FirstSong
	.area .text
_FirstSong:
	.word	0
	.word	__Rhythm1
	.word	__Rhythm2
	.word	__Lead
	.globl _main
_main:
	jsr	_Game
	rts
	.area .bss
	.globl	_SelectedSong
_SelectedSong:	.blkb	2
	.globl	_Pressed
_Pressed:	.blkb	1
	.globl	_duration
_duration:	.blkb	1
	.globl	_duration2
_duration2:	.blkb	1
	.globl	_duration3
_duration3:	.blkb	1
	.globl	_note
_note:	.blkb	2
	.globl	_durationSum
_durationSum:	.blkb	2
	.globl	_channelCounter
_channelCounter:	.blkb	1
