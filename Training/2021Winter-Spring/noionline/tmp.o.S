
tmp.o:     file format pe-x86-64


Disassembly of section .text:

0000000000000000 <__tcf_0>:
   0:	48 8d 0d a0 f6 01 00 	lea    0x1f6a0(%rip),%rcx        # 1f6a7 <_ZStL8__ioinit+0x7>
   7:	e9 00 00 00 00       	jmp    c <__tcf_0+0xc>
   c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000000010 <_Z5scanfPKcz.constprop.0>:
  10:	53                   	push   %rbx
  11:	48 83 ec 30          	sub    $0x30,%rsp
  15:	31 c9                	xor    %ecx,%ecx
  17:	48 8d 5c 24 48       	lea    0x48(%rsp),%rbx
  1c:	48 89 54 24 48       	mov    %rdx,0x48(%rsp)
  21:	4c 89 44 24 50       	mov    %r8,0x50(%rsp)
  26:	4c 89 4c 24 58       	mov    %r9,0x58(%rsp)
  2b:	48 89 5c 24 28       	mov    %rbx,0x28(%rsp)
  30:	ff 15 00 00 00 00    	call   *0x0(%rip)        # 36 <_Z5scanfPKcz.constprop.0+0x26>
  36:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # 3d <_Z5scanfPKcz.constprop.0+0x2d>
  3d:	49 89 d8             	mov    %rbx,%r8
  40:	48 89 c1             	mov    %rax,%rcx
  43:	e8 00 00 00 00       	call   48 <_Z5scanfPKcz.constprop.0+0x38>
  48:	48 83 c4 30          	add    $0x30,%rsp
  4c:	5b                   	pop    %rbx
  4d:	c3                   	ret    
  4e:	90                   	nop
  4f:	90                   	nop

Disassembly of section .text$_Z6printfPKcz:

0000000000000000 <_Z6printfPKcz>:
   0:	41 54                	push   %r12
   2:	53                   	push   %rbx
   3:	48 83 ec 38          	sub    $0x38,%rsp
   7:	48 8d 5c 24 58       	lea    0x58(%rsp),%rbx
   c:	49 89 cc             	mov    %rcx,%r12
   f:	48 89 54 24 58       	mov    %rdx,0x58(%rsp)
  14:	b9 01 00 00 00       	mov    $0x1,%ecx
  19:	4c 89 44 24 60       	mov    %r8,0x60(%rsp)
  1e:	4c 89 4c 24 68       	mov    %r9,0x68(%rsp)
  23:	48 89 5c 24 28       	mov    %rbx,0x28(%rsp)
  28:	ff 15 00 00 00 00    	call   *0x0(%rip)        # 2e <_Z6printfPKcz+0x2e>
  2e:	49 89 d8             	mov    %rbx,%r8
  31:	4c 89 e2             	mov    %r12,%rdx
  34:	48 89 c1             	mov    %rax,%rcx
  37:	e8 00 00 00 00       	call   3c <_Z6printfPKcz+0x3c>
  3c:	48 83 c4 38          	add    $0x38,%rsp
  40:	5b                   	pop    %rbx
  41:	41 5c                	pop    %r12
  43:	c3                   	ret    
  44:	90                   	nop
  45:	90                   	nop
  46:	90                   	nop
  47:	90                   	nop
  48:	90                   	nop
  49:	90                   	nop
  4a:	90                   	nop
  4b:	90                   	nop
  4c:	90                   	nop
  4d:	90                   	nop
  4e:	90                   	nop
  4f:	90                   	nop

Disassembly of section .text.startup:

0000000000000000 <main>:
   0:	41 57                	push   %r15
   2:	41 56                	push   %r14
   4:	41 55                	push   %r13
   6:	41 54                	push   %r12
   8:	55                   	push   %rbp
   9:	57                   	push   %rdi
   a:	56                   	push   %rsi
   b:	53                   	push   %rbx
   c:	48 81 ec d8 02 00 00 	sub    $0x2d8,%rsp
  13:	0f 29 b4 24 50 02 00 	movaps %xmm6,0x250(%rsp)
  1a:	00 
  1b:	0f 29 bc 24 60 02 00 	movaps %xmm7,0x260(%rsp)
  22:	00 
  23:	44 0f 29 84 24 70 02 	movaps %xmm8,0x270(%rsp)
  2a:	00 00 
  2c:	44 0f 29 8c 24 80 02 	movaps %xmm9,0x280(%rsp)
  33:	00 00 
  35:	44 0f 29 94 24 90 02 	movaps %xmm10,0x290(%rsp)
  3c:	00 00 
  3e:	44 0f 29 9c 24 a0 02 	movaps %xmm11,0x2a0(%rsp)
  45:	00 00 
  47:	44 0f 29 a4 24 b0 02 	movaps %xmm12,0x2b0(%rsp)
  4e:	00 00 
  50:	44 0f 29 ac 24 c0 02 	movaps %xmm13,0x2c0(%rsp)
  57:	00 00 
  59:	e8 00 00 00 00       	call   5e <main+0x5e>
  5e:	31 c9                	xor    %ecx,%ecx
  60:	48 8b 1d 00 00 00 00 	mov    0x0(%rip),%rbx        # 67 <main+0x67>
  67:	ff d3                	call   *%rbx
  69:	48 8d 15 03 00 00 00 	lea    0x3(%rip),%rdx        # 73 <main+0x73>
  70:	48 8d 0d 05 00 00 00 	lea    0x5(%rip),%rcx        # 7c <main+0x7c>
  77:	49 89 c0             	mov    %rax,%r8
  7a:	e8 00 00 00 00       	call   7f <main+0x7f>
  7f:	b9 01 00 00 00       	mov    $0x1,%ecx
  84:	ff d3                	call   *%rbx
  86:	48 8d 15 10 00 00 00 	lea    0x10(%rip),%rdx        # 9d <main+0x9d>
  8d:	48 8d 0d 12 00 00 00 	lea    0x12(%rip),%rcx        # a6 <main+0xa6>
  94:	49 89 c0             	mov    %rax,%r8
  97:	e8 00 00 00 00       	call   9c <main+0x9c>
  9c:	48 8d 15 04 00 00 00 	lea    0x4(%rip),%rdx        # a7 <main+0xa7>
  a3:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # aa <main+0xaa>
  aa:	e8 10 00 00 00       	call   bf <main+0xbf>
  af:	8b 05 04 00 00 00    	mov    0x4(%rip),%eax        # b9 <main+0xb9>
  b5:	8d 50 ff             	lea    -0x1(%rax),%edx
  b8:	85 c0                	test   %eax,%eax
  ba:	89 15 04 00 00 00    	mov    %edx,0x4(%rip)        # c4 <main+0xc4>
  c0:	0f 84 ee 04 00 00    	je     5b4 <main+0x5b4>
  c6:	48 8d 84 24 d8 01 00 	lea    0x1d8(%rsp),%rax
  cd:	00 
  ce:	4c 8d b4 24 d0 01 00 	lea    0x1d0(%rsp),%r14
  d5:	00 
  d6:	48 89 84 24 c8 00 00 	mov    %rax,0xc8(%rsp)
  dd:	00 
  de:	4d 89 f4             	mov    %r14,%r12
  e1:	48 8d 15 00 00 00 00 	lea    0x0(%rip),%rdx        # e8 <main+0xe8>
  e8:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # ef <main+0xef>
  ef:	e8 10 00 00 00       	call   104 <main+0x104>
  f4:	4c 8b 84 24 c8 00 00 	mov    0xc8(%rsp),%r8
  fb:	00 
  fc:	48 8d 15 20 00 00 00 	lea    0x20(%rip),%rdx        # 123 <main+0x123>
 103:	31 c0                	xor    %eax,%eax
 105:	0f 1f 00             	nopl   (%rax)
 108:	b9 0f 00 00 00       	mov    $0xf,%ecx
 10d:	4c 89 c7             	mov    %r8,%rdi
 110:	48 c7 02 00 00 00 00 	movq   $0x0,(%rdx)
 117:	48 83 ea 80          	sub    $0xffffffffffffff80,%rdx
 11b:	f3 48 ab             	rep stos %rax,%es:(%rdi)
 11e:	48 8d 3d a0 f4 01 00 	lea    0x1f4a0(%rip),%rdi        # 1f5c5 <_GLOBAL__sub_I_a+0x1ec05>
 125:	48 c7 42 88 00 00 00 	movq   $0x0,-0x78(%rdx)
 12c:	00 
 12d:	48 c7 42 90 00 00 00 	movq   $0x0,-0x70(%rdx)
 134:	00 
 135:	48 c7 42 98 00 00 00 	movq   $0x0,-0x68(%rdx)
 13c:	00 
 13d:	48 c7 42 a0 00 00 00 	movq   $0x0,-0x60(%rdx)
 144:	00 
 145:	48 c7 42 a8 00 00 00 	movq   $0x0,-0x58(%rdx)
 14c:	00 
 14d:	48 c7 42 b0 00 00 00 	movq   $0x0,-0x50(%rdx)
 154:	00 
 155:	48 c7 42 b8 00 00 00 	movq   $0x0,-0x48(%rdx)
 15c:	00 
 15d:	48 c7 42 c0 00 00 00 	movq   $0x0,-0x40(%rdx)
 164:	00 
 165:	48 c7 42 c8 00 00 00 	movq   $0x0,-0x38(%rdx)
 16c:	00 
 16d:	48 c7 42 d0 00 00 00 	movq   $0x0,-0x30(%rdx)
 174:	00 
 175:	48 c7 42 d8 00 00 00 	movq   $0x0,-0x28(%rdx)
 17c:	00 
 17d:	48 c7 42 e0 00 00 00 	movq   $0x0,-0x20(%rdx)
 184:	00 
 185:	48 c7 42 e8 00 00 00 	movq   $0x0,-0x18(%rdx)
 18c:	00 
 18d:	48 c7 42 f0 00 00 00 	movq   $0x0,-0x10(%rdx)
 194:	00 
 195:	48 c7 42 f8 00 00 00 	movq   $0x0,-0x8(%rdx)
 19c:	00 
 19d:	48 39 fa             	cmp    %rdi,%rdx
 1a0:	48 c7 84 24 d0 01 00 	movq   $0x0,0x1d0(%rsp)
 1a7:	00 00 00 00 00 
 1ac:	0f 85 56 ff ff ff    	jne    108 <main+0x108>
 1b2:	8b 0d 00 00 00 00    	mov    0x0(%rip),%ecx        # 1b8 <main+0x1b8>
 1b8:	48 8d 9f 00 0c fe ff 	lea    -0x1f400(%rdi),%rbx
 1bf:	be 01 00 00 00       	mov    $0x1,%esi
 1c4:	bf 01 00 00 00       	mov    $0x1,%edi
 1c9:	4c 8d b4 24 50 01 00 	lea    0x150(%rsp),%r14
 1d0:	00 
 1d1:	85 c9                	test   %ecx,%ecx
 1d3:	0f 8e 9d 07 00 00    	jle    976 <main+0x976>
 1d9:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 1e0 <main+0x1e0>
 1e0:	4c 89 f2             	mov    %r14,%rdx
 1e3:	e8 10 00 00 00       	call   1f8 <main+0x1f8>
 1e8:	8b 94 24 50 01 00 00 	mov    0x150(%rsp),%edx
 1ef:	85 d2                	test   %edx,%edx
 1f1:	7e 4a                	jle    23d <main+0x23d>
 1f3:	bd 01 00 00 00       	mov    $0x1,%ebp
 1f8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 1ff:	00 
 200:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 207 <main+0x207>
 207:	4c 89 e2             	mov    %r12,%rdx
 20a:	e8 10 00 00 00       	call   21f <main+0x21f>
 20f:	48 63 84 24 d0 01 00 	movslq 0x1d0(%rsp),%rax
 216:	00 
 217:	48 3d ec 03 00 00    	cmp    $0x3ec,%rax
 21d:	48 89 c1             	mov    %rax,%rcx
 220:	0f 87 74 07 00 00    	ja     99a <main+0x99a>
 226:	48 c1 e8 05          	shr    $0x5,%rax
 22a:	89 f2                	mov    %esi,%edx
 22c:	83 c5 01             	add    $0x1,%ebp
 22f:	d3 e2                	shl    %cl,%edx
 231:	09 14 83             	or     %edx,(%rbx,%rax,4)
 234:	39 ac 24 50 01 00 00 	cmp    %ebp,0x150(%rsp)
 23b:	7d c3                	jge    200 <main+0x200>
 23d:	8b 05 00 00 00 00    	mov    0x0(%rip),%eax        # 243 <main+0x243>
 243:	83 c7 01             	add    $0x1,%edi
 246:	48 83 eb 80          	sub    $0xffffffffffffff80,%rbx
 24a:	39 f8                	cmp    %edi,%eax
 24c:	7d 8b                	jge    1d9 <main+0x1d9>
 24e:	85 c0                	test   %eax,%eax
 250:	89 84 24 b8 00 00 00 	mov    %eax,0xb8(%rsp)
 257:	0f 8e 19 07 00 00    	jle    976 <main+0x976>
 25d:	4c 8d 2d 20 01 00 00 	lea    0x120(%rip),%r13        # 384 <main+0x384>
 264:	83 c0 01             	add    $0x1,%eax
 267:	c7 84 24 b4 00 00 00 	movl   $0x1,0xb4(%rsp)
 26e:	01 00 00 00 
 272:	89 84 24 a4 00 00 00 	mov    %eax,0xa4(%rsp)
 279:	48 8d 84 24 d0 00 00 	lea    0xd0(%rsp),%rax
 280:	00 
 281:	48 89 84 24 a8 00 00 	mov    %rax,0xa8(%rsp)
 288:	00 
 289:	48 8d ac 24 50 02 00 	lea    0x250(%rsp),%rbp
 290:	00 
 291:	c7 84 24 c4 00 00 00 	movl   $0xffffffff,0xc4(%rsp)
 298:	ff ff ff ff 
 29c:	c7 84 24 c0 00 00 00 	movl   $0xffffffff,0xc0(%rsp)
 2a3:	ff ff ff ff 
 2a7:	8b bc 24 b4 00 00 00 	mov    0xb4(%rsp),%edi
 2ae:	89 bc 24 bc 00 00 00 	mov    %edi,0xbc(%rsp)
 2b5:	83 c7 01             	add    $0x1,%edi
 2b8:	39 bc 24 b8 00 00 00 	cmp    %edi,0xb8(%rsp)
 2bf:	89 bc 24 b4 00 00 00 	mov    %edi,0xb4(%rsp)
 2c6:	0f 8c aa 06 00 00    	jl     976 <main+0x976>
 2cc:	49 8b 45 80          	mov    -0x80(%r13),%rax
 2d0:	4c 89 ee             	mov    %r13,%rsi
 2d3:	c7 84 24 b0 00 00 00 	movl   $0x0,0xb0(%rsp)
 2da:	00 00 00 00 
 2de:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
 2e3:	49 8b 45 88          	mov    -0x78(%r13),%rax
 2e7:	48 89 44 24 68       	mov    %rax,0x68(%rsp)
 2ec:	49 8b 45 90          	mov    -0x70(%r13),%rax
 2f0:	48 89 44 24 70       	mov    %rax,0x70(%rsp)
 2f5:	49 8b 45 98          	mov    -0x68(%r13),%rax
 2f9:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
 2fe:	49 8b 45 a0          	mov    -0x60(%r13),%rax
 302:	48 89 84 24 80 00 00 	mov    %rax,0x80(%rsp)
 309:	00 
 30a:	49 8b 45 a8          	mov    -0x58(%r13),%rax
 30e:	48 89 84 24 88 00 00 	mov    %rax,0x88(%rsp)
 315:	00 
 316:	49 8b 45 b0          	mov    -0x50(%r13),%rax
 31a:	48 89 84 24 90 00 00 	mov    %rax,0x90(%rsp)
 321:	00 
 322:	49 8b 45 b8          	mov    -0x48(%r13),%rax
 326:	48 89 84 24 98 00 00 	mov    %rax,0x98(%rsp)
 32d:	00 
 32e:	49 8b 45 c0          	mov    -0x40(%r13),%rax
 332:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
 337:	49 8b 45 c8          	mov    -0x38(%r13),%rax
 33b:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
 340:	49 8b 45 d0          	mov    -0x30(%r13),%rax
 344:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
 349:	49 8b 45 d8          	mov    -0x28(%r13),%rax
 34d:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
 352:	49 8b 45 e0          	mov    -0x20(%r13),%rax
 356:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
 35b:	49 8b 45 e8          	mov    -0x18(%r13),%rax
 35f:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
 364:	49 8b 45 f0          	mov    -0x10(%r13),%rax
 368:	48 89 44 24 50       	mov    %rax,0x50(%rsp)
 36d:	49 8b 45 f8          	mov    -0x8(%r13),%rax
 371:	48 89 44 24 60       	mov    %rax,0x60(%rsp)
 376:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
 37d:	00 00 00 
 380:	48 8b 44 24 58       	mov    0x58(%rsp),%rax
 385:	31 db                	xor    %ebx,%ebx
 387:	48 89 84 24 d0 00 00 	mov    %rax,0xd0(%rsp)
 38e:	00 
 38f:	48 8b 44 24 68       	mov    0x68(%rsp),%rax
 394:	48 89 84 24 d8 00 00 	mov    %rax,0xd8(%rsp)
 39b:	00 
 39c:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
 3a1:	48 89 84 24 e0 00 00 	mov    %rax,0xe0(%rsp)
 3a8:	00 
 3a9:	48 8b 44 24 78       	mov    0x78(%rsp),%rax
 3ae:	48 89 84 24 e8 00 00 	mov    %rax,0xe8(%rsp)
 3b5:	00 
 3b6:	48 8b 84 24 80 00 00 	mov    0x80(%rsp),%rax
 3bd:	00 
 3be:	48 89 84 24 f0 00 00 	mov    %rax,0xf0(%rsp)
 3c5:	00 
 3c6:	48 8b 84 24 88 00 00 	mov    0x88(%rsp),%rax
 3cd:	00 
 3ce:	48 89 84 24 f8 00 00 	mov    %rax,0xf8(%rsp)
 3d5:	00 
 3d6:	48 8b 84 24 90 00 00 	mov    0x90(%rsp),%rax
 3dd:	00 
 3de:	48 89 84 24 00 01 00 	mov    %rax,0x100(%rsp)
 3e5:	00 
 3e6:	48 8b 84 24 98 00 00 	mov    0x98(%rsp),%rax
 3ed:	00 
 3ee:	48 89 84 24 08 01 00 	mov    %rax,0x108(%rsp)
 3f5:	00 
 3f6:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 3fb:	48 89 84 24 10 01 00 	mov    %rax,0x110(%rsp)
 402:	00 
 403:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
 408:	48 89 84 24 18 01 00 	mov    %rax,0x118(%rsp)
 40f:	00 
 410:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
 415:	48 89 84 24 20 01 00 	mov    %rax,0x120(%rsp)
 41c:	00 
 41d:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
 422:	48 89 84 24 28 01 00 	mov    %rax,0x128(%rsp)
 429:	00 
 42a:	48 8b 44 24 40       	mov    0x40(%rsp),%rax
 42f:	48 89 84 24 30 01 00 	mov    %rax,0x130(%rsp)
 436:	00 
 437:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
 43c:	48 89 84 24 38 01 00 	mov    %rax,0x138(%rsp)
 443:	00 
 444:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
 449:	48 89 84 24 40 01 00 	mov    %rax,0x140(%rsp)
 450:	00 
 451:	48 8b 44 24 60       	mov    0x60(%rsp),%rax
 456:	48 89 84 24 48 01 00 	mov    %rax,0x148(%rsp)
 45d:	00 
 45e:	66 44 0f 6f ac 24 d0 	movdqa 0xd0(%rsp),%xmm13
 465:	00 00 00 
 468:	66 44 0f db 2e       	pand   (%rsi),%xmm13
 46d:	4c 8b bc 24 a8 00 00 	mov    0xa8(%rsp),%r15
 474:	00 
 475:	44 0f 29 ac 24 d0 00 	movaps %xmm13,0xd0(%rsp)
 47c:	00 00 
 47e:	66 44 0f 6f a4 24 e0 	movdqa 0xe0(%rsp),%xmm12
 485:	00 00 00 
 488:	66 44 0f db 66 10    	pand   0x10(%rsi),%xmm12
 48e:	44 0f 29 a4 24 e0 00 	movaps %xmm12,0xe0(%rsp)
 495:	00 00 
 497:	66 44 0f 6f 9c 24 f0 	movdqa 0xf0(%rsp),%xmm11
 49e:	00 00 00 
 4a1:	66 44 0f db 5e 20    	pand   0x20(%rsi),%xmm11
 4a7:	44 0f 29 9c 24 f0 00 	movaps %xmm11,0xf0(%rsp)
 4ae:	00 00 
 4b0:	66 44 0f 6f 94 24 00 	movdqa 0x100(%rsp),%xmm10
 4b7:	01 00 00 
 4ba:	66 44 0f db 56 30    	pand   0x30(%rsi),%xmm10
 4c0:	44 0f 29 94 24 00 01 	movaps %xmm10,0x100(%rsp)
 4c7:	00 00 
 4c9:	66 44 0f 6f 8c 24 10 	movdqa 0x110(%rsp),%xmm9
 4d0:	01 00 00 
 4d3:	66 44 0f db 4e 40    	pand   0x40(%rsi),%xmm9
 4d9:	44 0f 29 8c 24 10 01 	movaps %xmm9,0x110(%rsp)
 4e0:	00 00 
 4e2:	66 44 0f 6f 84 24 20 	movdqa 0x120(%rsp),%xmm8
 4e9:	01 00 00 
 4ec:	66 44 0f db 46 50    	pand   0x50(%rsi),%xmm8
 4f2:	44 0f 29 84 24 20 01 	movaps %xmm8,0x120(%rsp)
 4f9:	00 00 
 4fb:	66 0f 6f bc 24 30 01 	movdqa 0x130(%rsp),%xmm7
 502:	00 00 
 504:	66 0f db 7e 60       	pand   0x60(%rsi),%xmm7
 509:	0f 29 bc 24 30 01 00 	movaps %xmm7,0x130(%rsp)
 510:	00 
 511:	66 0f 6f 76 70       	movdqa 0x70(%rsi),%xmm6
 516:	66 0f db b4 24 40 01 	pand   0x140(%rsp),%xmm6
 51d:	00 00 
 51f:	0f 29 b4 24 40 01 00 	movaps %xmm6,0x140(%rsp)
 526:	00 
 527:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 52e:	00 00 
 530:	41 8b 0f             	mov    (%r15),%ecx
 533:	49 83 c7 04          	add    $0x4,%r15
 537:	e8 00 00 00 00       	call   53c <main+0x53c>
 53c:	48 98                	cltq   
 53e:	48 01 c3             	add    %rax,%rbx
 541:	4d 39 f7             	cmp    %r14,%r15
 544:	75 ea                	jne    530 <main+0x530>
 546:	48 85 db             	test   %rbx,%rbx
 549:	0f 85 c1 00 00 00    	jne    610 <main+0x610>
 54f:	83 c7 01             	add    $0x1,%edi
 552:	48 83 ee 80          	sub    $0xffffffffffffff80,%rsi
 556:	3b bc 24 a4 00 00 00 	cmp    0xa4(%rsp),%edi
 55d:	0f 85 1d fe ff ff    	jne    380 <main+0x380>
 563:	8b 84 24 b0 00 00 00 	mov    0xb0(%rsp),%eax
 56a:	49 83 ed 80          	sub    $0xffffffffffffff80,%r13
 56e:	85 c0                	test   %eax,%eax
 570:	0f 84 31 fd ff ff    	je     2a7 <main+0x2a7>
 576:	48 8d 0d 67 00 00 00 	lea    0x67(%rip),%rcx        # 5e4 <main+0x5e4>
 57d:	e8 00 00 00 00       	call   582 <main+0x582>
 582:	44 8b 84 24 c4 00 00 	mov    0xc4(%rsp),%r8d
 589:	00 
 58a:	48 8d 0d 6b 00 00 00 	lea    0x6b(%rip),%rcx        # 5fc <main+0x5fc>
 591:	8b 94 24 c0 00 00 00 	mov    0xc0(%rsp),%edx
 598:	e8 00 00 00 00       	call   59d <main+0x59d>
 59d:	8b 05 04 00 00 00    	mov    0x4(%rip),%eax        # 5a7 <main+0x5a7>
 5a3:	8d 50 ff             	lea    -0x1(%rax),%edx
 5a6:	85 c0                	test   %eax,%eax
 5a8:	89 15 04 00 00 00    	mov    %edx,0x4(%rip)        # 5b2 <main+0x5b2>
 5ae:	0f 85 2d fb ff ff    	jne    e1 <main+0xe1>
 5b4:	0f 28 b4 24 50 02 00 	movaps 0x250(%rsp),%xmm6
 5bb:	00 
 5bc:	31 c0                	xor    %eax,%eax
 5be:	0f 28 bc 24 60 02 00 	movaps 0x260(%rsp),%xmm7
 5c5:	00 
 5c6:	44 0f 28 84 24 70 02 	movaps 0x270(%rsp),%xmm8
 5cd:	00 00 
 5cf:	44 0f 28 8c 24 80 02 	movaps 0x280(%rsp),%xmm9
 5d6:	00 00 
 5d8:	44 0f 28 94 24 90 02 	movaps 0x290(%rsp),%xmm10
 5df:	00 00 
 5e1:	44 0f 28 9c 24 a0 02 	movaps 0x2a0(%rsp),%xmm11
 5e8:	00 00 
 5ea:	44 0f 28 a4 24 b0 02 	movaps 0x2b0(%rsp),%xmm12
 5f1:	00 00 
 5f3:	44 0f 28 ac 24 c0 02 	movaps 0x2c0(%rsp),%xmm13
 5fa:	00 00 
 5fc:	48 81 c4 d8 02 00 00 	add    $0x2d8,%rsp
 603:	5b                   	pop    %rbx
 604:	5e                   	pop    %rsi
 605:	5f                   	pop    %rdi
 606:	5d                   	pop    %rbp
 607:	41 5c                	pop    %r12
 609:	41 5d                	pop    %r13
 60b:	41 5e                	pop    %r14
 60d:	41 5f                	pop    %r15
 60f:	c3                   	ret    
 610:	48 8b 44 24 58       	mov    0x58(%rsp),%rax
 615:	4d 89 f7             	mov    %r14,%r15
 618:	31 db                	xor    %ebx,%ebx
 61a:	48 89 84 24 50 01 00 	mov    %rax,0x150(%rsp)
 621:	00 
 622:	48 8b 44 24 68       	mov    0x68(%rsp),%rax
 627:	48 89 84 24 58 01 00 	mov    %rax,0x158(%rsp)
 62e:	00 
 62f:	48 8b 44 24 70       	mov    0x70(%rsp),%rax
 634:	48 89 84 24 60 01 00 	mov    %rax,0x160(%rsp)
 63b:	00 
 63c:	48 8b 44 24 78       	mov    0x78(%rsp),%rax
 641:	48 89 84 24 68 01 00 	mov    %rax,0x168(%rsp)
 648:	00 
 649:	48 8b 84 24 80 00 00 	mov    0x80(%rsp),%rax
 650:	00 
 651:	48 89 84 24 70 01 00 	mov    %rax,0x170(%rsp)
 658:	00 
 659:	48 8b 84 24 88 00 00 	mov    0x88(%rsp),%rax
 660:	00 
 661:	48 89 84 24 78 01 00 	mov    %rax,0x178(%rsp)
 668:	00 
 669:	48 8b 84 24 90 00 00 	mov    0x90(%rsp),%rax
 670:	00 
 671:	48 89 84 24 80 01 00 	mov    %rax,0x180(%rsp)
 678:	00 
 679:	48 8b 84 24 98 00 00 	mov    0x98(%rsp),%rax
 680:	00 
 681:	48 89 84 24 88 01 00 	mov    %rax,0x188(%rsp)
 688:	00 
 689:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 68e:	48 89 84 24 90 01 00 	mov    %rax,0x190(%rsp)
 695:	00 
 696:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
 69b:	48 89 84 24 98 01 00 	mov    %rax,0x198(%rsp)
 6a2:	00 
 6a3:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
 6a8:	48 89 84 24 a0 01 00 	mov    %rax,0x1a0(%rsp)
 6af:	00 
 6b0:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
 6b5:	48 89 84 24 a8 01 00 	mov    %rax,0x1a8(%rsp)
 6bc:	00 
 6bd:	48 8b 44 24 40       	mov    0x40(%rsp),%rax
 6c2:	48 89 84 24 b0 01 00 	mov    %rax,0x1b0(%rsp)
 6c9:	00 
 6ca:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
 6cf:	48 89 84 24 b8 01 00 	mov    %rax,0x1b8(%rsp)
 6d6:	00 
 6d7:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
 6dc:	48 89 84 24 c0 01 00 	mov    %rax,0x1c0(%rsp)
 6e3:	00 
 6e4:	48 8b 44 24 60       	mov    0x60(%rsp),%rax
 6e9:	48 89 84 24 c8 01 00 	mov    %rax,0x1c8(%rsp)
 6f0:	00 
 6f1:	66 0f 6f 84 24 50 01 	movdqa 0x150(%rsp),%xmm0
 6f8:	00 00 
 6fa:	66 41 0f ef c5       	pxor   %xmm13,%xmm0
 6ff:	0f 29 84 24 50 01 00 	movaps %xmm0,0x150(%rsp)
 706:	00 
 707:	66 0f 6f 84 24 60 01 	movdqa 0x160(%rsp),%xmm0
 70e:	00 00 
 710:	66 41 0f ef c4       	pxor   %xmm12,%xmm0
 715:	0f 29 84 24 60 01 00 	movaps %xmm0,0x160(%rsp)
 71c:	00 
 71d:	66 0f 6f 84 24 70 01 	movdqa 0x170(%rsp),%xmm0
 724:	00 00 
 726:	66 41 0f ef c3       	pxor   %xmm11,%xmm0
 72b:	0f 29 84 24 70 01 00 	movaps %xmm0,0x170(%rsp)
 732:	00 
 733:	66 0f 6f 84 24 80 01 	movdqa 0x180(%rsp),%xmm0
 73a:	00 00 
 73c:	66 41 0f ef c2       	pxor   %xmm10,%xmm0
 741:	0f 29 84 24 80 01 00 	movaps %xmm0,0x180(%rsp)
 748:	00 
 749:	66 0f 6f 84 24 90 01 	movdqa 0x190(%rsp),%xmm0
 750:	00 00 
 752:	66 41 0f ef c1       	pxor   %xmm9,%xmm0
 757:	0f 29 84 24 90 01 00 	movaps %xmm0,0x190(%rsp)
 75e:	00 
 75f:	66 0f 6f 84 24 a0 01 	movdqa 0x1a0(%rsp),%xmm0
 766:	00 00 
 768:	66 41 0f ef c0       	pxor   %xmm8,%xmm0
 76d:	0f 29 84 24 a0 01 00 	movaps %xmm0,0x1a0(%rsp)
 774:	00 
 775:	66 0f 6f 84 24 b0 01 	movdqa 0x1b0(%rsp),%xmm0
 77c:	00 00 
 77e:	66 0f ef c7          	pxor   %xmm7,%xmm0
 782:	0f 29 84 24 b0 01 00 	movaps %xmm0,0x1b0(%rsp)
 789:	00 
 78a:	66 0f 6f 84 24 c0 01 	movdqa 0x1c0(%rsp),%xmm0
 791:	00 00 
 793:	66 0f ef c6          	pxor   %xmm6,%xmm0
 797:	0f 29 84 24 c0 01 00 	movaps %xmm0,0x1c0(%rsp)
 79e:	00 
 79f:	90                   	nop
 7a0:	41 8b 0f             	mov    (%r15),%ecx
 7a3:	49 83 c7 04          	add    $0x4,%r15
 7a7:	e8 00 00 00 00       	call   7ac <main+0x7ac>
 7ac:	48 98                	cltq   
 7ae:	48 01 c3             	add    %rax,%rbx
 7b1:	4d 39 e7             	cmp    %r12,%r15
 7b4:	75 ea                	jne    7a0 <main+0x7a0>
 7b6:	48 85 db             	test   %rbx,%rbx
 7b9:	0f 84 90 fd ff ff    	je     54f <main+0x54f>
 7bf:	48 8b 06             	mov    (%rsi),%rax
 7c2:	4d 89 e7             	mov    %r12,%r15
 7c5:	31 db                	xor    %ebx,%ebx
 7c7:	48 89 84 24 d0 01 00 	mov    %rax,0x1d0(%rsp)
 7ce:	00 
 7cf:	48 8b 46 08          	mov    0x8(%rsi),%rax
 7d3:	48 89 84 24 d8 01 00 	mov    %rax,0x1d8(%rsp)
 7da:	00 
 7db:	48 8b 46 10          	mov    0x10(%rsi),%rax
 7df:	48 89 84 24 e0 01 00 	mov    %rax,0x1e0(%rsp)
 7e6:	00 
 7e7:	48 8b 46 18          	mov    0x18(%rsi),%rax
 7eb:	48 89 84 24 e8 01 00 	mov    %rax,0x1e8(%rsp)
 7f2:	00 
 7f3:	48 8b 46 20          	mov    0x20(%rsi),%rax
 7f7:	48 89 84 24 f0 01 00 	mov    %rax,0x1f0(%rsp)
 7fe:	00 
 7ff:	48 8b 46 28          	mov    0x28(%rsi),%rax
 803:	48 89 84 24 f8 01 00 	mov    %rax,0x1f8(%rsp)
 80a:	00 
 80b:	48 8b 46 30          	mov    0x30(%rsi),%rax
 80f:	48 89 84 24 00 02 00 	mov    %rax,0x200(%rsp)
 816:	00 
 817:	48 8b 46 38          	mov    0x38(%rsi),%rax
 81b:	48 89 84 24 08 02 00 	mov    %rax,0x208(%rsp)
 822:	00 
 823:	48 8b 46 40          	mov    0x40(%rsi),%rax
 827:	48 89 84 24 10 02 00 	mov    %rax,0x210(%rsp)
 82e:	00 
 82f:	48 8b 46 48          	mov    0x48(%rsi),%rax
 833:	48 89 84 24 18 02 00 	mov    %rax,0x218(%rsp)
 83a:	00 
 83b:	48 8b 46 50          	mov    0x50(%rsi),%rax
 83f:	48 89 84 24 20 02 00 	mov    %rax,0x220(%rsp)
 846:	00 
 847:	48 8b 46 58          	mov    0x58(%rsi),%rax
 84b:	48 89 84 24 28 02 00 	mov    %rax,0x228(%rsp)
 852:	00 
 853:	48 8b 46 60          	mov    0x60(%rsi),%rax
 857:	48 89 84 24 30 02 00 	mov    %rax,0x230(%rsp)
 85e:	00 
 85f:	48 8b 46 68          	mov    0x68(%rsi),%rax
 863:	48 89 84 24 38 02 00 	mov    %rax,0x238(%rsp)
 86a:	00 
 86b:	48 8b 46 70          	mov    0x70(%rsi),%rax
 86f:	48 89 84 24 40 02 00 	mov    %rax,0x240(%rsp)
 876:	00 
 877:	48 8b 46 78          	mov    0x78(%rsi),%rax
 87b:	48 89 84 24 48 02 00 	mov    %rax,0x248(%rsp)
 882:	00 
 883:	66 44 0f ef ac 24 d0 	pxor   0x1d0(%rsp),%xmm13
 88a:	01 00 00 
 88d:	66 44 0f ef a4 24 e0 	pxor   0x1e0(%rsp),%xmm12
 894:	01 00 00 
 897:	66 44 0f ef 9c 24 f0 	pxor   0x1f0(%rsp),%xmm11
 89e:	01 00 00 
 8a1:	66 44 0f ef 94 24 00 	pxor   0x200(%rsp),%xmm10
 8a8:	02 00 00 
 8ab:	66 44 0f ef 8c 24 10 	pxor   0x210(%rsp),%xmm9
 8b2:	02 00 00 
 8b5:	66 44 0f ef 84 24 20 	pxor   0x220(%rsp),%xmm8
 8bc:	02 00 00 
 8bf:	66 0f ef bc 24 30 02 	pxor   0x230(%rsp),%xmm7
 8c6:	00 00 
 8c8:	66 0f ef b4 24 40 02 	pxor   0x240(%rsp),%xmm6
 8cf:	00 00 
 8d1:	44 0f 29 ac 24 d0 01 	movaps %xmm13,0x1d0(%rsp)
 8d8:	00 00 
 8da:	44 0f 29 a4 24 e0 01 	movaps %xmm12,0x1e0(%rsp)
 8e1:	00 00 
 8e3:	44 0f 29 9c 24 f0 01 	movaps %xmm11,0x1f0(%rsp)
 8ea:	00 00 
 8ec:	44 0f 29 94 24 00 02 	movaps %xmm10,0x200(%rsp)
 8f3:	00 00 
 8f5:	44 0f 29 8c 24 10 02 	movaps %xmm9,0x210(%rsp)
 8fc:	00 00 
 8fe:	44 0f 29 84 24 20 02 	movaps %xmm8,0x220(%rsp)
 905:	00 00 
 907:	0f 29 bc 24 30 02 00 	movaps %xmm7,0x230(%rsp)
 90e:	00 
 90f:	0f 29 b4 24 40 02 00 	movaps %xmm6,0x240(%rsp)
 916:	00 
 917:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 91e:	00 00 
 920:	41 8b 0f             	mov    (%r15),%ecx
 923:	49 83 c7 04          	add    $0x4,%r15
 927:	e8 00 00 00 00       	call   92c <main+0x92c>
 92c:	48 98                	cltq   
 92e:	48 01 c3             	add    %rax,%rbx
 931:	4c 39 fd             	cmp    %r15,%rbp
 934:	75 ea                	jne    920 <main+0x920>
 936:	48 85 db             	test   %rbx,%rbx
 939:	0f 84 10 fc ff ff    	je     54f <main+0x54f>
 93f:	8d 47 01             	lea    0x1(%rdi),%eax
 942:	48 83 ee 80          	sub    $0xffffffffffffff80,%rsi
 946:	3b 84 24 a4 00 00 00 	cmp    0xa4(%rsp),%eax
 94d:	89 bc 24 c4 00 00 00 	mov    %edi,0xc4(%rsp)
 954:	74 31                	je     987 <main+0x987>
 956:	c7 84 24 b0 00 00 00 	movl   $0x1,0xb0(%rsp)
 95d:	01 00 00 00 
 961:	89 c7                	mov    %eax,%edi
 963:	8b 84 24 bc 00 00 00 	mov    0xbc(%rsp),%eax
 96a:	89 84 24 c0 00 00 00 	mov    %eax,0xc0(%rsp)
 971:	e9 0a fa ff ff       	jmp    380 <main+0x380>
 976:	48 8d 0d 64 00 00 00 	lea    0x64(%rip),%rcx        # 9e1 <_GLOBAL__sub_I_a+0x21>
 97d:	e8 00 00 00 00       	call   982 <main+0x982>
 982:	e9 16 fc ff ff       	jmp    59d <main+0x59d>
 987:	8b 84 24 bc 00 00 00 	mov    0xbc(%rsp),%eax
 98e:	89 84 24 c0 00 00 00 	mov    %eax,0xc0(%rsp)
 995:	e9 dc fb ff ff       	jmp    576 <main+0x576>
 99a:	48 8d 15 1e 00 00 00 	lea    0x1e(%rip),%rdx        # 9bf <main+0x9bf>
 9a1:	49 89 c0             	mov    %rax,%r8
 9a4:	41 b9 ed 03 00 00    	mov    $0x3ed,%r9d
 9aa:	48 8d 0d 30 00 00 00 	lea    0x30(%rip),%rcx        # 9e1 <_GLOBAL__sub_I_a+0x21>
 9b1:	e8 00 00 00 00       	call   9b6 <main+0x9b6>
 9b6:	90                   	nop
 9b7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 9be:	00 00 

00000000000009c0 <_GLOBAL__sub_I_a>:
 9c0:	48 83 ec 28          	sub    $0x28,%rsp
 9c4:	48 8d 0d a0 f6 01 00 	lea    0x1f6a0(%rip),%rcx        # 2006b <_ZStL8__ioinit+0x9cb>
 9cb:	e8 00 00 00 00       	call   9d0 <_GLOBAL__sub_I_a+0x10>
 9d0:	48 8d 0d 00 00 00 00 	lea    0x0(%rip),%rcx        # 9d7 <_GLOBAL__sub_I_a+0x17>
 9d7:	48 83 c4 28          	add    $0x28,%rsp
 9db:	e9 00 00 00 00       	jmp    9e0 <_GLOBAL__sub_I_a+0x20>
