.align 32

.section .text
.globl getMemOpCycles
getMemOpCycles:
  push %ebp
  mov %esp, %ebp
  push %ebx
  push %edi

  movl 8(%ebp), %edi

  xor %eax, %eax
  cpuid
  rdtsc
  mov %eax, (%edi)
  xor %eax, %eax
  cpuid
  rdtsc
  mov (%edi), %ebx
  sub %ebx, %eax

  pop %edi
  pop %ebx
  mov %ebp, %esp
  pop %ebp
  ret
