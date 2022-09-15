
main.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0004 	ldr	r0, [pc, #4]	; 14 <main+0x14>
   c:	ebfffffe 	bl	0 <Uart_send_string>
  10:	e8bd8800 	pop	{fp, pc}
  14:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <buff>:
   0:	6d68616d 	stfvse	f6, [r8, #-436]!	; 0xfffffe4c
   4:	2064756f 	rsbcs	r7, r4, pc, ror #10
   8:	72687361 	rsbvc	r7, r8, #-2080374783	; 0x84000001
   c:	4c206661 	stcmi	6, cr6, [r0], #-388	; 0xfffffe7c
  10:	6e726165 	rpwvssz	f6, f2, f5
  14:	74697720 	strbtvc	r7, [r9], #-1824	; 0x720
  18:	656b2068 	strbvs	r2, [fp, #-104]!	; 0x68
  1c:	6f6c6f72 	svcvs	0x006c6f72
  20:	00000073 	andeq	r0, r0, r3, ror r0
	...

Disassembly of section .rodata:

00000000 <buff2>:
   0:	6d68616d 	stfvse	f6, [r8, #-436]!	; 0xfffffe4c
   4:	2064756f 	rsbcs	r7, r4, pc, ror #10
   8:	72687361 	rsbvc	r7, r8, #-2080374783	; 0x84000001
   c:	00006661 	andeq	r6, r0, r1, ror #12
  10:	00000000 	andeq	r0, r0, r0

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	2029554e 	eorcs	r5, r9, lr, asr #10
   c:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  10:	Address 0x00000010 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003141 	andeq	r3, r0, r1, asr #2
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000027 	andeq	r0, r0, r7, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0x239
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0x109
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	011a0119 	tsteq	sl, r9, lsl r1
  30:	Address 0x00000030 is out of bounds.

