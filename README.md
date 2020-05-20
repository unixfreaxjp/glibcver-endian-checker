# glibcver-endian-checker
A code to check GNU base libc version and endianness.

Purpose: RE, Incident and Response or DFIR related.

in Japanese:

「DFIRの皆さん」が侵害されたLinux システムの標準GNU C実行ライブラリ環境(glibc)とエンディアン情報を高速に検出するのに役立つ簡単なC言語でツールをコーディングしました。

ビットのチェックやOS predefined macroの認識のツールがいくつかありますけど、glibcバーションとエンディアンの CLIでのネイティブな直ぐにチェックが出来るツールが何故か見つかりませんでしたので、その原因でさくっと作りました。

一応GNU系のLinuxOS、Intel以外プロセッサーを搭載したサーバ、若しくは IoT や ICS 組み込み器械、特にホットフォレンジックと IR 対応プロセスの時に便利かと思います。コード的に珍しくはないですけど便利なので自分もよく使っていますし、そろそろ公開したほうがいいかと思いました。インシデントの対応する時にぜひ使って下さい。もし変更したい場合fork経由でお願いいたします。 #seccamp 2017-2019 Z1の @unixfreaxjp

# howto

Requirement: gcc

Compilation and test run command:

```bash
$ gcc check-gcc-endian.c -o check-gcc-endian
$ ./check-gcc-endian
```

# size

If you worry for included library size, omit static build & strip it. 

If you compiled it as per it i as per above example, it will be a dynamically linked ELF w/symbols, and the size is about below (you can make it smaller using the advise above).

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
