# glibcver-endian-checker
A code to check GNU base libc version and endianness.

Purpose: RE, Incident and Response or DFIR related.

# howto

Compilation and test run command

```bash
$ gcc check-gcc-endian.c -o check-gcc-endian
$ ./check-gcc-endian
```

# size

if you worry for included library size, omit static & strip it. 

If you compiled it as per it i as per above example, it will be a dynamically linked ELF w/symbols, and the size is about below (you can make it smaller using the advise above.

```bash
$ file glibcver-endian-checker
glibcver-endian-checker: ELF 32-bit MSB executable, PowerPC or cisco 4500, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.26, not stripped
$ ls -alF glibcver-endian-checker|cut{blah}
6210 May 20 16:51 glibcver-endian-checker*
```

# working PoC

```
$ uname -smpio
Linux i686 unknown unknown GNU/Linux
$ gcc check-gcc-endian.c -o check-gcc-endian
$ ./check-gcc-endian
Checked Glibc ver: 2.19
Checked Endian: LittleEndian

----- snip ----

$ uname -snmpio
Linux armv5tejl unknown unknown GNU/Linux
$ ./check-gcc-endian
Checked Glibc ver: 2.22
Checked Endian: LittleEndian

----- snip ----

$ uname -smpio
Linux mips unknown unknown GNU/Linux
$ ./glibcver-endian-checker
Checked Glibc ver: 2.13
Checked Endian: BigEndian

----- snip ----

$ uname -smpio
Linux ppc unknown unknown GNU/Linux
$ ./glibcver-endian-checker
Checked Glibc ver: 2.13
Checked Endian: BigEndian
$
$
$ date
Thu May 21 00:35:58 JST 2020
$ # @unixfreaxjp
$
```

# bug maintainance - memo

contact: @unixfreaxjp 

# license 

<a href=https://en.wikipedia.org/wiki/WTFPL>WTFPL version 2</a>
