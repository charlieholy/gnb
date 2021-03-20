[pechen@zhong-yan-b3dev-rhel7 test]$ cat t.cpp
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
  unsigned long rbp = (unsigned long)((char*)malloc(32));
  memset((void*)rbp,0x78,29);
  //*((unsigned long*)rbp) = 0LL;
  *((unsigned long*)rbp) = 0;
  cout << "asd:" << hex << rbp << endl;
  return 0;
}


[pechen@zhong-yan-b3dev-rhel7 test]$ gdb ./a.out
GNU gdb (GDB) Red Hat Enterprise Linux 7.6.1-119.el7
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
Reading symbols from /var/fpwork/pechen/test/a.out...done.
(gdb) b main
Breakpoint 1 at 0x400915: file t.cpp, line 7.
(gdb) r
Starting program: /var/fpwork/pechen/test/./a.out

Breakpoint 1, main () at t.cpp:7
7         unsigned long rbp = (unsigned long)((char*)malloc(32));
Missing separate debuginfos, use: debuginfo-install glibc-2.17-307.el7.1.x86_64 libgcc-4.8.5-39.el7.x86_64 libstdc++-4.8.5-39.el7.x86_64
(gdb) n
8         memset((void*)rbp,0x78,29);
(gdb)
10        *((unsigned long*)rbp) = 0;
(gdb)
11        cout << "asd:" << hex << rbp << endl;
(gdb)
asd:603010
12        return 0;
(gdb) x /64xb 0x603010
0x603010:       0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x603018:       0x78    0x78    0x78    0x78    0x78    0x78    0x78    0x78
0x603020:       0x78    0x78    0x78    0x78    0x78    0x78    0x78    0x78
0x603028:       0x78    0x78    0x78    0x78    0x78    0x00    0x00    0x00
0x603030:       0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x603038:       0xd1    0x0f    0x02    0x00    0x00    0x00    0x00    0x00
0x603040:       0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
0x603048:       0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
