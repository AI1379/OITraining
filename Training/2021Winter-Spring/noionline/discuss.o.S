
discuss.o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <__tcf_0>:
   0:	48 8d 0d 20 f9 01 00 	lea    0x1f920(%rip),%rcx        # 1f927 <_ZStL8__ioinit+0x7>
   7:	e9 00 00 00 00       	jmp    c <__tcf_0+0xc>
   c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000010 <_Z5solvev>:
  10:	41 57                	push   %r15
  12:	41 56                	push   %r14
  14:	41 55                	push   %r13
  16:	41 54                	push   %r12
  18:	55                   	push   %rbp
  19:	57                   	push   %rdi
  1a:	56                   	push   %rsi
  1b:	53                   	push   %rbx
  1c:	48 81 ec e8 02 00 00 	sub    $0x2e8,%rsp
  23:	0f 29 b4 24 60 02 00 	movaps %xmm6,0x260(%rsp)
  2a:	00 
  2b:	0f 29 bc 24 70 02 00 	movaps %xmm7,0x270(%rsp)
  32:	00 
  33:	44 0f 29 84 24 80 02 	movaps %xmm8,0x280(%rsp)
  3a:	00 00 
  3c:	44 0f 29 8c 24 90 02 	movaps %xmm9,0x290(%rsp)
  43:	00 00 
  45:	44 0f 29 94 24 a0 02 	movaps %xmm10,0x2a0(%rsp)
  4c:	00 00 
  4e:	44 0f 29 9c 24 b0 02 	movaps %xmm11,0x2b0(%rsp)
  55:	00 00 
  57:	44 0f 29 a4 24 c0 02 	movaps %xmm12,0x2c0(%rsp)
  5e:	00 00 
  60:	44 0f 29 ac 24 d0 02 	movaps %xmm13,0x2d0(%rsp)
  67:	00 00 
  69:	48 8b 35 00 00 00 00 	mov    0x0(%rip),%rsi        # 70 <_Z5solvev+0x60>
  70:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 77 <_Z5solvev+0x67>
  77:	48 89 f1             	mov    %rsi,%rcx
  7a:	e8 00 00 00 00       	call   7f <_Z5solvev+0x6f>
  7f:	48 8d 15 20 00 00 00 	lea    0x20(%rip),%rdx        # a6 <_Z5solvev+0x96>
  86:	31 c0                	xor    %eax,%eax
  88:	4c 8d 8a 00 f9 01 00 	lea    0x1f900(%rdx),%r9
  8f:	4c 8d 84 24 e8 01 00 	lea    0x1e8(%rsp),%r8
  96:	00 
  97:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  9e:	00 00 
  a0:	48 c7 02 00 00 00 00 	movq   $0x0,(%rdx)
  a7:	48 83 ea 80          	sub    $0xffffffffffffff80,%rdx
  ab:	b9 0f 00 00 00       	mov    $0xf,%ecx
  b0:	4c 89 c7             	mov    %r8,%rdi
  b3:	48 c7 42 88 00 00 00 	movq   $0x0,-0x78(%rdx)
  ba:	00 
  bb:	48 c7 42 90 00 00 00 	movq   $0x0,-0x70(%rdx)
  c2:	00 
  c3:	48 c7 42 98 00 00 00 	movq   $0x0,-0x68(%rdx)
  ca:	00 
  cb:	48 c7 42 a0 00 00 00 	movq   $0x0,-0x60(%rdx)
  d2:	00 
  d3:	48 c7 42 a8 00 00 00 	movq   $0x0,-0x58(%rdx)
  da:	00 
  db:	48 c7 42 b0 00 00 00 	movq   $0x0,-0x50(%rdx)
  e2:	00 
  e3:	48 c7 42 b8 00 00 00 	movq   $0x0,-0x48(%rdx)
  ea:	00 
  eb:	48 c7 42 c0 00 00 00 	movq   $0x0,-0x40(%rdx)
  f2:	00 
  f3:	48 c7 42 c8 00 00 00 	movq   $0x0,-0x38(%rdx)
  fa:	00 
  fb:	48 c7 42 d0 00 00 00 	movq   $0x0,-0x30(%rdx)
 102:	00 
 103:	48 c7 42 d8 00 00 00 	movq   $0x0,-0x28(%rdx)
 10a:	00 
 10b:	48 c7 42 e0 00 00 00 	movq   $0x0,-0x20(%rdx)
 112:	00 
 113:	f3 48 ab             	rep stos %rax,%es:(%rdi)
 116:	48 c7 42 e8 00 00 00 	movq   $0x0,-0x18(%rdx)
 11d:	00 
 11e:	48 c7 42 f0 00 00 00 	movq   $0x0,-0x10(%rdx)
 125:	00 
 126:	48 c7 42 f8 00 00 00 	movq   $0x0,-0x8(%rdx)
 12d:	00 
 12e:	4c 39 ca             	cmp    %r9,%rdx
 131:	48 c7 84 24 e0 01 00 	movq   $0x0,0x1e0(%rsp)
 138:	00 00 00 00 00 
 13d:	0f 85 5d ff ff ff    	jne    a0 <_Z5solvev+0x90>
 143:	48 8d 1d a0 00 00 00 	lea    0xa0(%rip),%rbx        # 1ea <_Z5solvev+0x1da>
 14a:	45 31 e4             	xor    %r12d,%r12d
 14d:	bf 01 00 00 00       	mov    $0x1,%edi
 152:	48 83 3d ff ff ff ff 	cmpq   $0x0,-0x1(%rip)        # 159 <_Z5solvev+0x149>
 159:	00 
 15a:	4c 8d ac 24 d8 00 00 	lea    0xd8(%rsp),%r13
 161:	00 
 162:	48 8d ac 24 d0 00 00 	lea    0xd0(%rsp),%rbp
 169:	00 
 16a:	7e 73                	jle    1df <_Z5solvev+0x1cf>
 16c:	4c 89 ea             	mov    %r13,%rdx
 16f:	48 89 f1             	mov    %rsi,%rcx
 172:	45 31 f6             	xor    %r14d,%r14d
 175:	e8 00 00 00 00       	call   17a <_Z5solvev+0x16a>
 17a:	48 83 bc 24 d8 00 00 	cmpq   $0x0,0xd8(%rsp)
 181:	00 00 
 183:	7e 3c                	jle    1c1 <_Z5solvev+0x1b1>
 185:	0f 1f 00             	nopl   (%rax)
 188:	48 89 ea             	mov    %rbp,%rdx
 18b:	48 89 f1             	mov    %rsi,%rcx
 18e:	e8 00 00 00 00       	call   193 <_Z5solvev+0x183>
 193:	48 8b 8c 24 d0 00 00 	mov    0xd0(%rsp),%rcx
 19a:	00 
 19b:	89 fa                	mov    %edi,%edx
 19d:	48 89 c8             	mov    %rcx,%rax
 1a0:	83 e1 1f             	and    $0x1f,%ecx
 1a3:	48 c1 e8 05          	shr    $0x5,%rax
 1a7:	d3 e2                	shl    %cl,%edx
 1a9:	09 14 83             	or     %edx,(%rbx,%rax,4)
 1ac:	4c 89 f0             	mov    %r14,%rax
 1af:	49 83 c6 01          	add    $0x1,%r14
 1b3:	48 83 c0 02          	add    $0x2,%rax
 1b7:	48 39 84 24 d8 00 00 	cmp    %rax,0xd8(%rsp)
 1be:	00 
 1bf:	7d c7                	jge    188 <_Z5solvev+0x178>
 1c1:	48 8b 05 00 00 00 00 	mov    0x0(%rip),%rax        # 1c8 <_Z5solvev+0x1b8>
 1c8:	49 8d 54 24 01       	lea    0x1(%r12),%rdx
 1cd:	49 83 c4 02          	add    $0x2,%r12
 1d1:	48 83 eb 80          	sub    $0xffffffffffffff80,%rbx
 1d5:	4c 39 e0             	cmp    %r12,%rax
 1d8:	7c 5f                	jl     239 <_Z5solvev+0x229>
 1da:	49 89 d4             	mov    %rdx,%r12
 1dd:	eb 8d                	jmp    16c <_Z5solvev+0x15c>
 1df:	4c 8b 25 00 00 00 00 	mov    0x0(%rip),%r12        # 1e6 <_Z5solvev+0x1d6>
 1e6:	41 b8 02 00 00 00    	mov    $0x2,%r8d
 1ec:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 1f3 <_Z5solvev+0x1e3>
 1f3:	4c 89 e1             	mov    %r12,%rcx
 1f6:	e8 00 00 00 00       	call   1fb <_Z5solvev+0x1eb>
 1fb:	49 8b 04 24          	mov    (%r12),%rax
 1ff:	48 8b 40 e8          	mov    -0x18(%rax),%rax
 203:	4e 8b ac 20 f0 00 00 	mov    0xf0(%rax,%r12,1),%r13
 20a:	00 
 20b:	4d 85 ed             	test   %r13,%r13
 20e:	0f 84 57 09 00 00    	je     b6b <_Z5solvev+0xb5b>
 214:	41 80 7d 38 00       	cmpb   $0x0,0x38(%r13)
 219:	0f 84 91 08 00 00    	je     ab0 <_Z5solvev+0xaa0>
 21f:	41 0f be 55 43       	movsbl 0x43(%r13),%edx
 224:	4c 89 e1             	mov    %r12,%rcx
 227:	e8 00 00 00 00       	call   22c <_Z5solvev+0x21c>
 22c:	48 89 c1             	mov    %rax,%rcx
 22f:	e8 00 00 00 00       	call   234 <_Z5solvev+0x224>
 234:	e9 1d 08 00 00       	jmp    a56 <_Z5solvev+0xa46>
 239:	48 85 c0             	test   %rax,%rax
 23c:	48 89 84 24 90 00 00 	mov    %rax,0x90(%rsp)
 243:	00 
 244:	7e 99                	jle    1df <_Z5solvev+0x1cf>
 246:	48 8d 05 20 01 00 00 	lea    0x120(%rip),%rax        # 36d <_Z5solvev+0x35d>
 24d:	48 c7 84 24 c8 00 00 	movq   $0xffffffffffffffff,0xc8(%rsp)
 254:	00 ff ff ff ff 
 259:	48 89 84 24 b0 00 00 	mov    %rax,0xb0(%rsp)
 260:	00 
 261:	4c 8d a4 24 60 01 00 	lea    0x160(%rsp),%r12
 268:	00 
 269:	48 c7 84 24 c0 00 00 	movq   $0xffffffffffffffff,0xc0(%rsp)
 270:	00 ff ff ff ff 
 275:	4c 8d b4 24 e0 01 00 	lea    0x1e0(%rsp),%r14
 27c:	00 
 27d:	48 c7 84 24 a8 00 00 	movq   $0x1,0xa8(%rsp)
 284:	00 01 00 00 00 
 289:	48 8d ac 24 60 02 00 	lea    0x260(%rsp),%rbp
 290:	00 
 291:	48 8b 84 24 a8 00 00 	mov    0xa8(%rsp),%rax
 298:	00 
 299:	48 8d 78 01          	lea    0x1(%rax),%rdi
 29d:	48 39 bc 24 90 00 00 	cmp    %rdi,0x90(%rsp)
 2a4:	00 
 2a5:	48 89 84 24 b8 00 00 	mov    %rax,0xb8(%rsp)
 2ac:	00 
 2ad:	48 89 bc 24 a8 00 00 	mov    %rdi,0xa8(%rsp)
 2b4:	00 
 2b5:	0f 8c 24 ff ff ff    	jl     1df <_Z5solvev+0x1cf>
 2bb:	48 8b 84 24 b0 00 00 	mov    0xb0(%rsp),%rax
 2c2:	00 
 2c3:	c6 84 24 a7 00 00 00 	movb   $0x0,0xa7(%rsp)
 2ca:	00 
 2cb:	48 8b 50 88          	mov    -0x78(%rax),%rdx
 2cf:	48 89 c6             	mov    %rax,%rsi
 2d2:	4c 8b 78 80          	mov    -0x80(%rax),%r15
 2d6:	48 89 94 24 98 00 00 	mov    %rdx,0x98(%rsp)
 2dd:	00 
 2de:	48 8b 50 90          	mov    -0x70(%rax),%rdx
 2e2:	48 89 54 24 28       	mov    %rdx,0x28(%rsp)
 2e7:	48 8b 50 98          	mov    -0x68(%rax),%rdx
 2eb:	48 89 54 24 30       	mov    %rdx,0x30(%rsp)
 2f0:	48 8b 50 a0          	mov    -0x60(%rax),%rdx
 2f4:	48 89 54 24 38       	mov    %rdx,0x38(%rsp)
 2f9:	48 8b 50 a8          	mov    -0x58(%rax),%rdx
 2fd:	48 89 54 24 40       	mov    %rdx,0x40(%rsp)
 302:	48 8b 50 b0          	mov    -0x50(%rax),%rdx
 306:	48 89 54 24 48       	mov    %rdx,0x48(%rsp)
 30b:	48 8b 50 b8          	mov    -0x48(%rax),%rdx
 30f:	48 89 54 24 50       	mov    %rdx,0x50(%rsp)
 314:	48 8b 50 c0          	mov    -0x40(%rax),%rdx
 318:	48 89 54 24 58       	mov    %rdx,0x58(%rsp)
 31d:	48 8b 50 c8          	mov    -0x38(%rax),%rdx
 321:	48 89 54 24 60       	mov    %rdx,0x60(%rsp)
 326:	48 8b 50 d0          	mov    -0x30(%rax),%rdx
 32a:	48 89 54 24 68       	mov    %rdx,0x68(%rsp)
 32f:	48 8b 50 d8          	mov    -0x28(%rax),%rdx
 333:	48 89 54 24 70       	mov    %rdx,0x70(%rsp)
 338:	48 8b 50 e0          	mov    -0x20(%rax),%rdx
 33c:	48 89 54 24 78       	mov    %rdx,0x78(%rsp)
 341:	48 8b 50 e8          	mov    -0x18(%rax),%rdx
 345:	48 89 94 24 80 00 00 	mov    %rdx,0x80(%rsp)
 34c:	00 
 34d:	48 8b 50 f0          	mov    -0x10(%rax),%rdx
 351:	48 8b 40 f8          	mov    -0x8(%rax),%rax
 355:	48 89 94 24 88 00 00 	mov    %rdx,0x88(%rsp)
 35c:	00 
 35d:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
 362:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
 368:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
 36d:	4c 89 bc 24 e0 01 00 	mov    %r15,0x1e0(%rsp)
 374:	00 
 375:	48 8b 54 24 30       	mov    0x30(%rsp),%rdx
 37a:	48 8b 5c 24 38       	mov    0x38(%rsp),%rbx
 37f:	48 8b 4c 24 40       	mov    0x40(%rsp),%rcx
 384:	4c 8b 54 24 48       	mov    0x48(%rsp),%r10
 389:	48 89 84 24 f0 01 00 	mov    %rax,0x1f0(%rsp)
 390:	00 
 391:	4c 8b 5c 24 50       	mov    0x50(%rsp),%r11
 396:	48 89 94 24 f8 01 00 	mov    %rdx,0x1f8(%rsp)
 39d:	00 
 39e:	4c 8b ac 24 98 00 00 	mov    0x98(%rsp),%r13
 3a5:	00 
 3a6:	48 89 9c 24 00 02 00 	mov    %rbx,0x200(%rsp)
 3ad:	00 
 3ae:	4c 8b 4c 24 58       	mov    0x58(%rsp),%r9
 3b3:	48 89 8c 24 08 02 00 	mov    %rcx,0x208(%rsp)
 3ba:	00 
 3bb:	4c 8b 44 24 60       	mov    0x60(%rsp),%r8
 3c0:	4c 89 94 24 10 02 00 	mov    %r10,0x210(%rsp)
 3c7:	00 
 3c8:	48 8b 44 24 68       	mov    0x68(%rsp),%rax
 3cd:	4c 89 9c 24 18 02 00 	mov    %r11,0x218(%rsp)
 3d4:	00 
 3d5:	48 8b 54 24 70       	mov    0x70(%rsp),%rdx
 3da:	4c 89 ac 24 e8 01 00 	mov    %r13,0x1e8(%rsp)
 3e1:	00 
 3e2:	48 8b 5c 24 78       	mov    0x78(%rsp),%rbx
 3e7:	4c 89 8c 24 20 02 00 	mov    %r9,0x220(%rsp)
 3ee:	00 
 3ef:	48 8b 8c 24 80 00 00 	mov    0x80(%rsp),%rcx
 3f6:	00 
 3f7:	4c 89 84 24 28 02 00 	mov    %r8,0x228(%rsp)
 3fe:	00 
 3ff:	4c 8b 94 24 88 00 00 	mov    0x88(%rsp),%r10
 406:	00 
 407:	48 89 84 24 30 02 00 	mov    %rax,0x230(%rsp)
 40e:	00 
 40f:	4c 8b 5c 24 20       	mov    0x20(%rsp),%r11
 414:	48 89 94 24 38 02 00 	mov    %rdx,0x238(%rsp)
 41b:	00 
 41c:	48 89 9c 24 40 02 00 	mov    %rbx,0x240(%rsp)
 423:	00 
 424:	66 44 0f 6f ac 24 e0 	movdqa 0x1e0(%rsp),%xmm13
 42b:	01 00 00 
 42e:	48 89 8c 24 48 02 00 	mov    %rcx,0x248(%rsp)
 435:	00 
 436:	4c 89 94 24 50 02 00 	mov    %r10,0x250(%rsp)
 43d:	00 
 43e:	4c 89 9c 24 58 02 00 	mov    %r11,0x258(%rsp)
 445:	00 
 446:	66 44 0f db 2e       	pand   (%rsi),%xmm13
 44b:	66 44 0f 6f a4 24 f0 	movdqa 0x1f0(%rsp),%xmm12
 452:	01 00 00 
 455:	66 44 0f db 66 10    	pand   0x10(%rsi),%xmm12
 45b:	44 0f 29 ac 24 e0 01 	movaps %xmm13,0x1e0(%rsp)
 462:	00 00 
 464:	66 0f 6f 76 70       	movdqa 0x70(%rsi),%xmm6
 469:	66 0f db b4 24 50 02 	pand   0x250(%rsp),%xmm6
 470:	00 00 
 472:	48 8b 9c 24 e8 01 00 	mov    0x1e8(%rsp),%rbx
 479:	00 
 47a:	44 0f 29 a4 24 f0 01 	movaps %xmm12,0x1f0(%rsp)
 481:	00 00 
 483:	4c 8b 9c 24 f8 01 00 	mov    0x1f8(%rsp),%r11
 48a:	00 
 48b:	0f 29 b4 24 50 02 00 	movaps %xmm6,0x250(%rsp)
 492:	00 
 493:	66 44 0f 6f 9c 24 00 	movdqa 0x200(%rsp),%xmm11
 49a:	02 00 00 
 49d:	66 44 0f db 5e 20    	pand   0x20(%rsi),%xmm11
 4a3:	44 0f 29 9c 24 00 02 	movaps %xmm11,0x200(%rsp)
 4aa:	00 00 
 4ac:	4c 8b 94 24 08 02 00 	mov    0x208(%rsp),%r10
 4b3:	00 
 4b4:	66 44 0f d6 ac 24 e0 	movq   %xmm13,0xe0(%rsp)
 4bb:	00 00 00 
 4be:	66 44 0f 6f 94 24 10 	movdqa 0x210(%rsp),%xmm10
 4c5:	02 00 00 
 4c8:	66 44 0f db 56 30    	pand   0x30(%rsi),%xmm10
 4ce:	48 89 9c 24 e8 00 00 	mov    %rbx,0xe8(%rsp)
 4d5:	00 
 4d6:	66 44 0f 6f 8c 24 20 	movdqa 0x220(%rsp),%xmm9
 4dd:	02 00 00 
 4e0:	4c 89 9c 24 f8 00 00 	mov    %r11,0xf8(%rsp)
 4e7:	00 
 4e8:	66 44 0f db 4e 40    	pand   0x40(%rsi),%xmm9
 4ee:	66 44 0f 6f 84 24 30 	movdqa 0x230(%rsp),%xmm8
 4f5:	02 00 00 
 4f8:	66 44 0f db 46 50    	pand   0x50(%rsi),%xmm8
 4fe:	44 0f 29 94 24 10 02 	movaps %xmm10,0x210(%rsp)
 505:	00 00 
 507:	66 0f 6f bc 24 40 02 	movdqa 0x240(%rsp),%xmm7
 50e:	00 00 
 510:	66 0f db 7e 60       	pand   0x60(%rsi),%xmm7
 515:	4c 89 94 24 08 01 00 	mov    %r10,0x108(%rsp)
 51c:	00 
 51d:	44 0f 29 8c 24 20 02 	movaps %xmm9,0x220(%rsp)
 524:	00 00 
 526:	44 0f 29 84 24 30 02 	movaps %xmm8,0x230(%rsp)
 52d:	00 00 
 52f:	0f 29 bc 24 40 02 00 	movaps %xmm7,0x240(%rsp)
 536:	00 
 537:	66 44 0f d6 a4 24 f0 	movq   %xmm12,0xf0(%rsp)
 53e:	00 00 00 
 541:	66 44 0f d6 9c 24 00 	movq   %xmm11,0x100(%rsp)
 548:	01 00 00 
 54b:	66 44 0f d6 94 24 10 	movq   %xmm10,0x110(%rsp)
 552:	01 00 00 
 555:	48 8b 5c 24 38       	mov    0x38(%rsp),%rbx
 55a:	4c 8b 8c 24 18 02 00 	mov    0x218(%rsp),%r9
 561:	00 
 562:	4c 89 ac 24 68 01 00 	mov    %r13,0x168(%rsp)
 569:	00 
 56a:	4d 89 e5             	mov    %r12,%r13
 56d:	4c 8b 84 24 28 02 00 	mov    0x228(%rsp),%r8
 574:	00 
 575:	4c 89 bc 24 60 01 00 	mov    %r15,0x160(%rsp)
 57c:	00 
 57d:	48 8b 8c 24 38 02 00 	mov    0x238(%rsp),%rcx
 584:	00 
 585:	66 44 0f d6 8c 24 20 	movq   %xmm9,0x120(%rsp)
 58c:	01 00 00 
 58f:	48 8b 94 24 48 02 00 	mov    0x248(%rsp),%rdx
 596:	00 
 597:	48 89 9c 24 80 01 00 	mov    %rbx,0x180(%rsp)
 59e:	00 
 59f:	48 8b 84 24 58 02 00 	mov    0x258(%rsp),%rax
 5a6:	00 
 5a7:	4c 89 8c 24 18 01 00 	mov    %r9,0x118(%rsp)
 5ae:	00 
 5af:	4c 8b 54 24 48       	mov    0x48(%rsp),%r10
 5b4:	4c 89 84 24 28 01 00 	mov    %r8,0x128(%rsp)
 5bb:	00 
 5bc:	4c 8b 5c 24 50       	mov    0x50(%rsp),%r11
 5c1:	48 89 8c 24 38 01 00 	mov    %rcx,0x138(%rsp)
 5c8:	00 
 5c9:	4c 8b 4c 24 58       	mov    0x58(%rsp),%r9
 5ce:	48 89 94 24 48 01 00 	mov    %rdx,0x148(%rsp)
 5d5:	00 
 5d6:	48 8b 4c 24 40       	mov    0x40(%rsp),%rcx
 5db:	48 89 84 24 58 01 00 	mov    %rax,0x158(%rsp)
 5e2:	00 
 5e3:	48 8b 54 24 30       	mov    0x30(%rsp),%rdx
 5e8:	4c 89 94 24 90 01 00 	mov    %r10,0x190(%rsp)
 5ef:	00 
 5f0:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
 5f5:	4c 89 9c 24 98 01 00 	mov    %r11,0x198(%rsp)
 5fc:	00 
 5fd:	4c 8b 44 24 60       	mov    0x60(%rsp),%r8
 602:	66 44 0f d6 84 24 30 	movq   %xmm8,0x130(%rsp)
 609:	01 00 00 
 60c:	48 89 8c 24 88 01 00 	mov    %rcx,0x188(%rsp)
 613:	00 
 614:	48 89 94 24 78 01 00 	mov    %rdx,0x178(%rsp)
 61b:	00 
 61c:	66 0f d6 bc 24 40 01 	movq   %xmm7,0x140(%rsp)
 623:	00 00 
 625:	66 0f d6 b4 24 50 01 	movq   %xmm6,0x150(%rsp)
 62c:	00 00 
 62e:	48 89 84 24 70 01 00 	mov    %rax,0x170(%rsp)
 635:	00 
 636:	4c 89 8c 24 a0 01 00 	mov    %r9,0x1a0(%rsp)
 63d:	00 
 63e:	4c 89 84 24 a8 01 00 	mov    %r8,0x1a8(%rsp)
 645:	00 
 646:	48 8b 44 24 68       	mov    0x68(%rsp),%rax
 64b:	66 0f 6f 84 24 60 01 	movdqa 0x160(%rsp),%xmm0
 652:	00 00 
 654:	48 8b 54 24 70       	mov    0x70(%rsp),%rdx
 659:	66 41 0f ef c5       	pxor   %xmm13,%xmm0
 65e:	0f 29 84 24 60 01 00 	movaps %xmm0,0x160(%rsp)
 665:	00 
 666:	66 0f 6f 84 24 70 01 	movdqa 0x170(%rsp),%xmm0
 66d:	00 00 
 66f:	48 8b 5c 24 78       	mov    0x78(%rsp),%rbx
 674:	48 89 84 24 b0 01 00 	mov    %rax,0x1b0(%rsp)
 67b:	00 
 67c:	66 41 0f ef c4       	pxor   %xmm12,%xmm0
 681:	0f 29 84 24 70 01 00 	movaps %xmm0,0x170(%rsp)
 688:	00 
 689:	4c 8b 5c 24 20       	mov    0x20(%rsp),%r11
 68e:	48 8b 8c 24 80 00 00 	mov    0x80(%rsp),%rcx
 695:	00 
 696:	48 89 94 24 b8 01 00 	mov    %rdx,0x1b8(%rsp)
 69d:	00 
 69e:	66 0f 6f 84 24 80 01 	movdqa 0x180(%rsp),%xmm0
 6a5:	00 00 
 6a7:	4c 8b 94 24 88 00 00 	mov    0x88(%rsp),%r10
 6ae:	00 
 6af:	48 89 9c 24 c0 01 00 	mov    %rbx,0x1c0(%rsp)
 6b6:	00 
 6b7:	31 db                	xor    %ebx,%ebx
 6b9:	66 41 0f ef c3       	pxor   %xmm11,%xmm0
 6be:	0f 29 84 24 80 01 00 	movaps %xmm0,0x180(%rsp)
 6c5:	00 
 6c6:	66 0f 6f 84 24 90 01 	movdqa 0x190(%rsp),%xmm0
 6cd:	00 00 
 6cf:	48 89 8c 24 c8 01 00 	mov    %rcx,0x1c8(%rsp)
 6d6:	00 
 6d7:	66 41 0f ef c2       	pxor   %xmm10,%xmm0
 6dc:	0f 29 84 24 90 01 00 	movaps %xmm0,0x190(%rsp)
 6e3:	00 
 6e4:	66 0f 6f 84 24 a0 01 	movdqa 0x1a0(%rsp),%xmm0
 6eb:	00 00 
 6ed:	4c 89 94 24 d0 01 00 	mov    %r10,0x1d0(%rsp)
 6f4:	00 
 6f5:	66 41 0f ef c1       	pxor   %xmm9,%xmm0
 6fa:	0f 29 84 24 a0 01 00 	movaps %xmm0,0x1a0(%rsp)
 701:	00 
 702:	66 0f 6f 84 24 b0 01 	movdqa 0x1b0(%rsp),%xmm0
 709:	00 00 
 70b:	4c 89 9c 24 d8 01 00 	mov    %r11,0x1d8(%rsp)
 712:	00 
 713:	66 41 0f ef c0       	pxor   %xmm8,%xmm0
 718:	0f 29 84 24 b0 01 00 	movaps %xmm0,0x1b0(%rsp)
 71f:	00 
 720:	66 0f 6f 84 24 c0 01 	movdqa 0x1c0(%rsp),%xmm0
 727:	00 00 
 729:	66 0f ef c7          	pxor   %xmm7,%xmm0
 72d:	0f 29 84 24 c0 01 00 	movaps %xmm0,0x1c0(%rsp)
 734:	00 
 735:	66 0f 6f 84 24 d0 01 	movdqa 0x1d0(%rsp),%xmm0
 73c:	00 00 
 73e:	66 0f ef c6          	pxor   %xmm6,%xmm0
 742:	0f 29 84 24 d0 01 00 	movaps %xmm0,0x1d0(%rsp)
 749:	00 
 74a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
 750:	41 8b 4d 00          	mov    0x0(%r13),%ecx
 754:	49 83 c5 04          	add    $0x4,%r13
 758:	e8 00 00 00 00       	call   75d <_Z5solvev+0x74d>
 75d:	48 98                	cltq   
 75f:	48 01 c3             	add    %rax,%rbx
 762:	4d 39 f5             	cmp    %r14,%r13
 765:	75 e9                	jne    750 <_Z5solvev+0x740>
 767:	48 85 db             	test   %rbx,%rbx
 76a:	75 1e                	jne    78a <_Z5solvev+0x77a>
 76c:	48 8d 47 01          	lea    0x1(%rdi),%rax
 770:	48 83 ee 80          	sub    $0xffffffffffffff80,%rsi
 774:	48 39 bc 24 90 00 00 	cmp    %rdi,0x90(%rsp)
 77b:	00 
 77c:	0f 84 f1 01 00 00    	je     973 <_Z5solvev+0x963>
 782:	48 89 c7             	mov    %rax,%rdi
 785:	e9 de fb ff ff       	jmp    368 <_Z5solvev+0x358>
 78a:	48 8b 06             	mov    (%rsi),%rax
 78d:	4d 89 f5             	mov    %r14,%r13
 790:	31 db                	xor    %ebx,%ebx
 792:	48 89 84 24 e0 01 00 	mov    %rax,0x1e0(%rsp)
 799:	00 
 79a:	48 8b 46 08          	mov    0x8(%rsi),%rax
 79e:	48 89 84 24 e8 01 00 	mov    %rax,0x1e8(%rsp)
 7a5:	00 
 7a6:	48 8b 46 10          	mov    0x10(%rsi),%rax
 7aa:	48 89 84 24 f0 01 00 	mov    %rax,0x1f0(%rsp)
 7b1:	00 
 7b2:	48 8b 46 18          	mov    0x18(%rsi),%rax
 7b6:	48 89 84 24 f8 01 00 	mov    %rax,0x1f8(%rsp)
 7bd:	00 
 7be:	48 8b 46 20          	mov    0x20(%rsi),%rax
 7c2:	48 89 84 24 00 02 00 	mov    %rax,0x200(%rsp)
 7c9:	00 
 7ca:	48 8b 46 28          	mov    0x28(%rsi),%rax
 7ce:	48 89 84 24 08 02 00 	mov    %rax,0x208(%rsp)
 7d5:	00 
 7d6:	48 8b 46 30          	mov    0x30(%rsi),%rax
 7da:	48 89 84 24 10 02 00 	mov    %rax,0x210(%rsp)
 7e1:	00 
 7e2:	48 8b 46 38          	mov    0x38(%rsi),%rax
 7e6:	48 89 84 24 18 02 00 	mov    %rax,0x218(%rsp)
 7ed:	00 
 7ee:	48 8b 46 40          	mov    0x40(%rsi),%rax
 7f2:	48 89 84 24 20 02 00 	mov    %rax,0x220(%rsp)
 7f9:	00 
 7fa:	48 8b 46 48          	mov    0x48(%rsi),%rax
 7fe:	48 89 84 24 28 02 00 	mov    %rax,0x228(%rsp)
 805:	00 
 806:	48 8b 46 50          	mov    0x50(%rsi),%rax
 80a:	48 89 84 24 30 02 00 	mov    %rax,0x230(%rsp)
 811:	00 
 812:	48 8b 46 58          	mov    0x58(%rsi),%rax
 816:	48 89 84 24 38 02 00 	mov    %rax,0x238(%rsp)
 81d:	00 
 81e:	48 8b 46 60          	mov    0x60(%rsi),%rax
 822:	48 89 84 24 40 02 00 	mov    %rax,0x240(%rsp)
 829:	00 
 82a:	48 8b 46 68          	mov    0x68(%rsi),%rax
 82e:	48 89 84 24 48 02 00 	mov    %rax,0x248(%rsp)
 835:	00 
 836:	48 8b 46 70          	mov    0x70(%rsi),%rax
 83a:	48 89 84 24 50 02 00 	mov    %rax,0x250(%rsp)
 841:	00 
 842:	48 8b 46 78          	mov    0x78(%rsi),%rax
 846:	48 89 84 24 58 02 00 	mov    %rax,0x258(%rsp)
 84d:	00 
 84e:	66 44 0f ef ac 24 e0 	pxor   0x1e0(%rsp),%xmm13
 855:	01 00 00 
 858:	66 44 0f ef a4 24 f0 	pxor   0x1f0(%rsp),%xmm12
 85f:	01 00 00 
 862:	66 44 0f ef 9c 24 00 	pxor   0x200(%rsp),%xmm11
 869:	02 00 00 
 86c:	66 44 0f ef 94 24 10 	pxor   0x210(%rsp),%xmm10
 873:	02 00 00 
 876:	66 44 0f ef 8c 24 20 	pxor   0x220(%rsp),%xmm9
 87d:	02 00 00 
 880:	66 44 0f ef 84 24 30 	pxor   0x230(%rsp),%xmm8
 887:	02 00 00 
 88a:	66 0f ef bc 24 40 02 	pxor   0x240(%rsp),%xmm7
 891:	00 00 
 893:	66 0f ef b4 24 50 02 	pxor   0x250(%rsp),%xmm6
 89a:	00 00 
 89c:	44 0f 29 ac 24 e0 01 	movaps %xmm13,0x1e0(%rsp)
 8a3:	00 00 
 8a5:	44 0f 29 a4 24 f0 01 	movaps %xmm12,0x1f0(%rsp)
 8ac:	00 00 
 8ae:	44 0f 29 9c 24 00 02 	movaps %xmm11,0x200(%rsp)
 8b5:	00 00 
 8b7:	44 0f 29 94 24 10 02 	movaps %xmm10,0x210(%rsp)
 8be:	00 00 
 8c0:	44 0f 29 8c 24 20 02 	movaps %xmm9,0x220(%rsp)
 8c7:	00 00 
 8c9:	44 0f 29 84 24 30 02 	movaps %xmm8,0x230(%rsp)
 8d0:	00 00 
 8d2:	0f 29 bc 24 40 02 00 	movaps %xmm7,0x240(%rsp)
 8d9:	00 
 8da:	0f 29 b4 24 50 02 00 	movaps %xmm6,0x250(%rsp)
 8e1:	00 
 8e2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
 8e8:	41 8b 4d 00          	mov    0x0(%r13),%ecx
 8ec:	49 83 c5 04          	add    $0x4,%r13
 8f0:	e8 00 00 00 00       	call   8f5 <_Z5solvev+0x8e5>
 8f5:	48 98                	cltq   
 8f7:	48 01 c3             	add    %rax,%rbx
 8fa:	49 39 ed             	cmp    %rbp,%r13
 8fd:	75 e9                	jne    8e8 <_Z5solvev+0x8d8>
 8ff:	48 85 db             	test   %rbx,%rbx
 902:	0f 84 64 fe ff ff    	je     76c <_Z5solvev+0x75c>
 908:	4c 8d ac 24 e0 00 00 	lea    0xe0(%rsp),%r13
 90f:	00 
 910:	31 db                	xor    %ebx,%ebx
 912:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
 918:	41 8b 4d 00          	mov    0x0(%r13),%ecx
 91c:	49 83 c5 04          	add    $0x4,%r13
 920:	e8 00 00 00 00       	call   925 <_Z5solvev+0x915>
 925:	48 98                	cltq   
 927:	48 01 c3             	add    %rax,%rbx
 92a:	4d 39 e5             	cmp    %r12,%r13
 92d:	75 e9                	jne    918 <_Z5solvev+0x908>
 92f:	48 85 db             	test   %rbx,%rbx
 932:	0f 84 34 fe ff ff    	je     76c <_Z5solvev+0x75c>
 938:	48 8d 47 01          	lea    0x1(%rdi),%rax
 93c:	48 83 ee 80          	sub    $0xffffffffffffff80,%rsi
 940:	48 39 bc 24 90 00 00 	cmp    %rdi,0x90(%rsp)
 947:	00 
 948:	0f 84 94 01 00 00    	je     ae2 <_Z5solvev+0xad2>
 94e:	48 89 bc 24 c8 00 00 	mov    %rdi,0xc8(%rsp)
 955:	00 
 956:	48 8b bc 24 b8 00 00 	mov    0xb8(%rsp),%rdi
 95d:	00 
 95e:	c6 84 24 a7 00 00 00 	movb   $0x1,0xa7(%rsp)
 965:	01 
 966:	48 89 bc 24 c0 00 00 	mov    %rdi,0xc0(%rsp)
 96d:	00 
 96e:	e9 0f fe ff ff       	jmp    782 <_Z5solvev+0x772>
 973:	48 83 ac 24 b0 00 00 	subq   $0xffffffffffffff80,0xb0(%rsp)
 97a:	00 80 
 97c:	80 bc 24 a7 00 00 00 	cmpb   $0x0,0xa7(%rsp)
 983:	00 
 984:	0f 84 07 f9 ff ff    	je     291 <_Z5solvev+0x281>
 98a:	4c 8b 25 00 00 00 00 	mov    0x0(%rip),%r12        # 991 <_Z5solvev+0x981>
 991:	41 b8 03 00 00 00    	mov    $0x3,%r8d
 997:	48 8d 15 03 00 00 00 	lea    0x3(%rip),%rdx        # 9a1 <_Z5solvev+0x991>
 99e:	4c 89 e1             	mov    %r12,%rcx
 9a1:	e8 00 00 00 00       	call   9a6 <_Z5solvev+0x996>
 9a6:	49 8b 04 24          	mov    (%r12),%rax
 9aa:	48 8b 40 e8          	mov    -0x18(%rax),%rax
 9ae:	4e 8b ac 20 f0 00 00 	mov    0xf0(%rax,%r12,1),%r13
 9b5:	00 
 9b6:	4d 85 ed             	test   %r13,%r13
 9b9:	0f 84 ac 01 00 00    	je     b6b <_Z5solvev+0xb5b>
 9bf:	41 80 7d 38 00       	cmpb   $0x0,0x38(%r13)
 9c4:	0f 84 6f 01 00 00    	je     b39 <_Z5solvev+0xb29>
 9ca:	41 0f be 55 43       	movsbl 0x43(%r13),%edx
 9cf:	4c 89 e1             	mov    %r12,%rcx
 9d2:	e8 00 00 00 00       	call   9d7 <_Z5solvev+0x9c7>
 9d7:	48 89 c1             	mov    %rax,%rcx
 9da:	e8 00 00 00 00       	call   9df <_Z5solvev+0x9cf>
 9df:	48 8b 94 24 c0 00 00 	mov    0xc0(%rsp),%rdx
 9e6:	00 
 9e7:	48 89 c1             	mov    %rax,%rcx
 9ea:	e8 00 00 00 00       	call   9ef <_Z5solvev+0x9df>
 9ef:	41 b8 01 00 00 00    	mov    $0x1,%r8d
 9f5:	4c 89 f2             	mov    %r14,%rdx
 9f8:	c6 84 24 e0 01 00 00 	movb   $0x20,0x1e0(%rsp)
 9ff:	20 
 a00:	48 89 c1             	mov    %rax,%rcx
 a03:	e8 00 00 00 00       	call   a08 <_Z5solvev+0x9f8>
 a08:	48 8b 94 24 c8 00 00 	mov    0xc8(%rsp),%rdx
 a0f:	00 
 a10:	48 89 c1             	mov    %rax,%rcx
 a13:	e8 00 00 00 00       	call   a18 <_Z5solvev+0xa08>
 a18:	49 89 c5             	mov    %rax,%r13
 a1b:	48 8b 00             	mov    (%rax),%rax
 a1e:	48 8b 40 e8          	mov    -0x18(%rax),%rax
 a22:	4d 8b a4 05 f0 00 00 	mov    0xf0(%r13,%rax,1),%r12
 a29:	00 
 a2a:	4d 85 e4             	test   %r12,%r12
 a2d:	0f 84 38 01 00 00    	je     b6b <_Z5solvev+0xb5b>
 a33:	41 80 7c 24 38 00    	cmpb   $0x0,0x38(%r12)
 a39:	0f 84 c8 00 00 00    	je     b07 <_Z5solvev+0xaf7>
 a3f:	41 0f be 54 24 43    	movsbl 0x43(%r12),%edx
 a45:	4c 89 e9             	mov    %r13,%rcx
 a48:	e8 00 00 00 00       	call   a4d <_Z5solvev+0xa3d>
 a4d:	48 89 c1             	mov    %rax,%rcx
 a50:	e8 00 00 00 00       	call   a55 <_Z5solvev+0xa45>
 a55:	90                   	nop
 a56:	0f 28 b4 24 60 02 00 	movaps 0x260(%rsp),%xmm6
 a5d:	00 
 a5e:	0f 28 bc 24 70 02 00 	movaps 0x270(%rsp),%xmm7
 a65:	00 
 a66:	44 0f 28 84 24 80 02 	movaps 0x280(%rsp),%xmm8
 a6d:	00 00 
 a6f:	44 0f 28 8c 24 90 02 	movaps 0x290(%rsp),%xmm9
 a76:	00 00 
 a78:	44 0f 28 94 24 a0 02 	movaps 0x2a0(%rsp),%xmm10
 a7f:	00 00 
 a81:	44 0f 28 9c 24 b0 02 	movaps 0x2b0(%rsp),%xmm11
 a88:	00 00 
 a8a:	44 0f 28 a4 24 c0 02 	movaps 0x2c0(%rsp),%xmm12
 a91:	00 00 
 a93:	44 0f 28 ac 24 d0 02 	movaps 0x2d0(%rsp),%xmm13
 a9a:	00 00 
 a9c:	48 81 c4 e8 02 00 00 	add    $0x2e8,%rsp
 aa3:	5b                   	pop    %rbx
 aa4:	5e                   	pop    %rsi
 aa5:	5f                   	pop    %rdi
 aa6:	5d                   	pop    %rbp
 aa7:	41 5c                	pop    %r12
 aa9:	41 5d                	pop    %r13
 aab:	41 5e                	pop    %r14
 aad:	41 5f                	pop    %r15
 aaf:	c3                   	ret    
 ab0:	4c 89 e9             	mov    %r13,%rcx
 ab3:	e8 00 00 00 00       	call   ab8 <_Z5solvev+0xaa8>
 ab8:	49 8b 45 00          	mov    0x0(%r13),%rax
 abc:	ba 0a 00 00 00       	mov    $0xa,%edx
 ac1:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # ac8 <_Z5solvev+0xab8>
 ac8:	48 8b 40 30          	mov    0x30(%rax),%rax
 acc:	48 39 c8             	cmp    %rcx,%rax
 acf:	0f 84 4f f7 ff ff    	je     224 <_Z5solvev+0x214>
 ad5:	4c 89 e9             	mov    %r13,%rcx
 ad8:	ff d0                	call   *%rax
 ada:	0f be d0             	movsbl %al,%edx
 add:	e9 42 f7 ff ff       	jmp    224 <_Z5solvev+0x214>
 ae2:	48 8b 84 24 90 00 00 	mov    0x90(%rsp),%rax
 ae9:	00 
 aea:	48 89 84 24 c8 00 00 	mov    %rax,0xc8(%rsp)
 af1:	00 
 af2:	48 8b 84 24 b8 00 00 	mov    0xb8(%rsp),%rax
 af9:	00 
 afa:	48 89 84 24 c0 00 00 	mov    %rax,0xc0(%rsp)
 b01:	00 
 b02:	e9 83 fe ff ff       	jmp    98a <_Z5solvev+0x97a>
 b07:	4c 89 e1             	mov    %r12,%rcx
 b0a:	e8 00 00 00 00       	call   b0f <_Z5solvev+0xaff>
 b0f:	49 8b 04 24          	mov    (%r12),%rax
 b13:	ba 0a 00 00 00       	mov    $0xa,%edx
 b18:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # b1f <_Z5solvev+0xb0f>
 b1f:	48 8b 40 30          	mov    0x30(%rax),%rax
 b23:	48 39 c8             	cmp    %rcx,%rax
 b26:	0f 84 19 ff ff ff    	je     a45 <_Z5solvev+0xa35>
 b2c:	4c 89 e1             	mov    %r12,%rcx
 b2f:	ff d0                	call   *%rax
 b31:	0f be d0             	movsbl %al,%edx
 b34:	e9 0c ff ff ff       	jmp    a45 <_Z5solvev+0xa35>
 b39:	4c 89 e9             	mov    %r13,%rcx
 b3c:	e8 00 00 00 00       	call   b41 <_Z5solvev+0xb31>
 b41:	49 8b 45 00          	mov    0x0(%r13),%rax
 b45:	ba 0a 00 00 00       	mov    $0xa,%edx
 b4a:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # b51 <_Z5solvev+0xb41>
 b51:	48 8b 40 30          	mov    0x30(%rax),%rax
 b55:	48 39 c8             	cmp    %rcx,%rax
 b58:	0f 84 71 fe ff ff    	je     9cf <_Z5solvev+0x9bf>
 b5e:	4c 89 e9             	mov    %r13,%rcx
 b61:	ff d0                	call   *%rax
 b63:	0f be d0             	movsbl %al,%edx
 b66:	e9 64 fe ff ff       	jmp    9cf <_Z5solvev+0x9bf>
 b6b:	e8 00 00 00 00       	call   b70 <_Z5solvev+0xb60>
 b70:	90                   	nop
 b71:	90                   	nop
 b72:	90                   	nop
 b73:	90                   	nop
 b74:	90                   	nop
 b75:	90                   	nop
 b76:	90                   	nop
 b77:	90                   	nop
 b78:	90                   	nop
 b79:	90                   	nop
 b7a:	90                   	nop
 b7b:	90                   	nop
 b7c:	90                   	nop
 b7d:	90                   	nop
 b7e:	90                   	nop
 b7f:	90                   	nop

Disassembly of section .text$_ZNKSt5ctypeIcE8do_widenEc:

0000000000000000 <_ZNKSt5ctypeIcE8do_widenEc>:
   0:	89 d0                	mov    %edx,%eax
   2:	c3                   	ret    
   3:	90                   	nop
   4:	90                   	nop
   5:	90                   	nop
   6:	90                   	nop
   7:	90                   	nop
   8:	90                   	nop
   9:	90                   	nop
   a:	90                   	nop
   b:	90                   	nop
   c:	90                   	nop
   d:	90                   	nop
   e:	90                   	nop
   f:	90                   	nop

Disassembly of section .text.startup:

0000000000000000 <main>:
   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	e8 00 00 00 00       	call   a <main+0xa>
   a:	48 8b 1d 00 00 00 00 	mov    0x0(%rip),%rbx        # 11 <main+0x11>
  11:	31 c9                	xor    %ecx,%ecx
  13:	ff d3                	call   *%rbx
  15:	48 8d 15 07 00 00 00 	lea    0x7(%rip),%rdx        # 23 <main+0x23>
  1c:	48 8d 0d 09 00 00 00 	lea    0x9(%rip),%rcx        # 2c <main+0x2c>
  23:	49 89 c0             	mov    %rax,%r8
  26:	e8 00 00 00 00       	call   2b <main+0x2b>
  2b:	b9 01 00 00 00       	mov    $0x1,%ecx
  30:	ff d3                	call   *%rbx
  32:	48 8d 15 14 00 00 00 	lea    0x14(%rip),%rdx        # 4d <main+0x4d>
  39:	48 8d 0d 16 00 00 00 	lea    0x16(%rip),%rcx        # 56 <main+0x56>
  40:	49 89 c0             	mov    %rax,%r8
  43:	e8 00 00 00 00       	call   48 <main+0x48>
  48:	48 8b 0d 00 00 00 00 	mov    0x0(%rip),%rcx        # 4f <main+0x4f>
  4f:	48 8d 15 08 00 00 00 	lea    0x8(%rip),%rdx        # 5e <main+0x5e>
  56:	e8 00 00 00 00       	call   5b <main+0x5b>
  5b:	eb 08                	jmp    65 <main+0x65>
  5d:	0f 1f 00             	nopl   (%rax)
  60:	e8 10 00 00 00       	call   75 <main+0x75>
  65:	48 8b 05 08 00 00 00 	mov    0x8(%rip),%rax        # 74 <main+0x74>
  6c:	48 8d 50 ff          	lea    -0x1(%rax),%rdx
  70:	48 85 c0             	test   %rax,%rax
  73:	48 89 15 08 00 00 00 	mov    %rdx,0x8(%rip)        # 82 <main+0x82>
  7a:	75 e4                	jne    60 <main+0x60>
  7c:	31 c0                	xor    %eax,%eax
  7e:	48 83 c4 20          	add    $0x20,%rsp
  82:	5b                   	pop    %rbx
  83:	c3                   	ret    
  84:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
  8b:	00 00 00 00 
  8f:	90                   	nop

0000000000000090 <_GLOBAL__sub_I_a>:
  90:	48 83 ec 28          	sub    $0x28,%rsp
  94:	48 8d 0d 20 f9 01 00 	lea    0x1f920(%rip),%rcx        # 1f9bb <_ZStL8__ioinit+0x9b>
  9b:	e8 00 00 00 00       	call   a0 <_GLOBAL__sub_I_a+0x10>
  a0:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # a7 <_GLOBAL__sub_I_a+0x17>
  a7:	48 83 c4 28          	add    $0x28,%rsp
  ab:	e9 00 00 00 00       	jmp    b0 <_GLOBAL__sub_I_a+0x20>
