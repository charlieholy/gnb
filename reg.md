void foo(int a,int b,int c,int d,int e,int f,int g,int h,int i, int j)
{
}

int main()
{
  foo(1,2,3,4,5,6,7,9,9,8);
}
[pechen@zhong-yan-b3dev-rhel7 test]$ g++ t.cpp -g
[pechen@zhong-yan-b3dev-rhel7 test]$ gdb ./a.out
GNU gdb (GDB) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-pc-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./a.out...
(gdb) b foo
Breakpoint 1 at 0x20113d: file t.cpp, line 3.
(gdb) r
Starting program: /var/fpwork/pechen/test/a.out

Breakpoint 1, foo (a=1, b=2, c=3, d=4, e=5, f=6, g=7, h=9, i=9, j=8) at t.cpp:3
3       }
(gdb) info r
rax            0x201140            2101568
rbx            0x0                 0
rcx            0x4                 4
rdx            0x3                 3
rsi            0x2                 2
rdi            0x1                 1
rbp            0x7fffffff5350      0x7fffffff5350
rsp            0x7fffffff5350      0x7fffffff5350
r8             0x5                 5
r9             0x6                 6
r10            0x7fffffff4820      140737488308256
r11            0x7ffff7712460      140737344775264
r12            0x201000            2101248
r13            0x7fffffff5460      140737488311392
r14            0x0                 0
r15            0x0                 0
rip            0x20113d            0x20113d <foo(int, int, int, int, int, int, int, int, int, int)+24>
eflags         0x246               [ PF ZF IF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
k0             0x0                 0
k1             0x0                 0
k2             0x0                 0
k3             0x0                 0
k4             0x0                 0
k5             0x0                 0
k6             0x0                 0
k7             0x0                 0
(gdb) x /128xb 0x7fffffff5350
0x7fffffff5350: 0x80    0x53    0xff    0xff    0xff    0x7f    0x00    0x00
0x7fffffff5358: 0x71    0x11    0x20    0x00    0x00    0x00    0x00    0x00
0x7fffffff5360: 0x07    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x7fffffff5368: 0x09    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x7fffffff5370: 0x09    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x7fffffff5378: 0x08    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x7fffffff5380: 0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x7fffffff5388: 0x55    0x25    0x71    0xf7    0xff    0x7f    0x00    0x00
0x7fffffff5390: 0x40    0x1f    0xff    0xf7    0xff    0x7f    0x00    0x00
0x7fffffff5398: 0x68    0x54    0xff    0xff    0xff    0x7f    0x00    0x00
0x7fffffff53a0: 0x40    0x1f    0xff    0xf7    0x01    0x00    0x00    0x00
0x7fffffff53a8: 0x40    0x11    0x20    0x00    0x00    0x00    0x00    0x00
0x7fffffff53b0: 0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x7fffffff53b8: 0x0a    0x1b    0x38    0x63    0x2a    0x2f    0x3a    0x56
0x7fffffff53c0: 0x00    0x10    0x20    0x00    0x00    0x00    0x00    0x00
0x7fffffff53c8: 0x60    0x54    0xff    0xff    0xff    0x7f    0x00    0x00
