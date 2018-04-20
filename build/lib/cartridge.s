
;;; gcc for m6809 : Feb 15 2016 21:40:10
;;; 4.3.6 (gcc6809)
;;; ABI version 1
;;; -mint8
	.module	cartridge.c
	.globl _game_header
	.area	.cartridge
_game_header:
	.byte	0x67
	.byte	0x20
	.byte	0x47
	.byte	0x43
	.byte	0x45
	.byte	0x20
	.byte	0x32
	.byte	0x30
	.byte	0x31
	.byte	0x38
	.byte	0x80
	.word	_Vec_Music_1
	.byte	-8
	.byte	80
	.byte	16
	.byte	-90
	.byte	0x4B
	.byte	0x45
	.byte	0x59
	.byte	0x42
	.byte	0x4F
	.byte	0x41
	.byte	0x52
	.byte	0x44
	.byte	0x20
	.byte	0x48
	.byte	0x45
	.byte	0x52
	.byte	0x4F
	.byte	0x80
	.byte	0x00
