Project Overview:
-----------------------------------
What is the project about? Provide a brief overview that includes the project's name, purpose, and target audience.

*The objective of this project was to implement a "simple" shell. This shell would be able to exit, read from /proc filesystems, and perform basic Lunux commands such as ls, echo, ps, and you can even run valgrind [or your program] as well. The target audience would be users who are familiar with Linux as they will understand the output of these commands as well as which commands to input.*

Helpful Sources
--------------
*I have attached these links which I used to help me with this project:* <br>
https://www.geeksforgeeks.org/strcmp-in-c/ <br>
https://www.scaler.com/topics/exit-function-in-c/ <br>
https://www.linux.com/news/discover-possibilities-proc-directory/ <br>
https://www.tutorialspoint.com/c_standard_library/c_function_isdigit.htm <br>
https://www.educative.io/answers/splitting-a-string-using-strtok-in-c <br>
https://www.geeksforgeeks.org/strcpy-in-c/ <br>
https://www.ibm.com/docs/en/i/7.4?topic=functions-atoi-convert-character-string-integer <br>
https://www.geeksforgeeks.org/strcat-in-c/ <br>
https://www.educative.io/answers/what-is-the-execvp-function-in-c <br>
https://www.guru99.com/c-file-input-output.html <br>

Example session
---------------
*Session 1:* <br>
./main_template 22 <br>
Unknown argument <br>

*Session 2:* <br>
<p> >> /proc/cpuinfo <br>
processor       : 0 <br>
vendor_id       : GenuineIntel <br>
cpu family      : 6 <br>
model           : 126 <br>
model name      : Intel(R) Core(TM) i5-1035G1 CPU @ 1.00GHz <br>
stepping        : 5 <br>
microcode       : 0xffffffff <br>
cpu MHz         : 1190.403 <br>
cache size      : 6144 KB <br>
physical id     : 0 <br>
siblings        : 2 <br>
core id         : 0 <br>
cpu cores       : 2 <br>
apicid          : 0 <br>
initial apicid  : 0 <br>
fpu             : yes <br>
fpu_exception   : yes <br>
cpuid level     : 22 <br>
wp              : yes <br>
flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 movbe popcnt aes rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single ibrs_enhanced fsgsbase bmi1 bmi2 invpcid rdseed clflushopt md_clear flush_l1d arch_capabilities <br>
bugs            : spectre_v1 spectre_v2 spec_store_bypass swapgs itlb_multihit srbds mmio_stale_data retbleed eibrs_pbrsb <br>
bogomips        : 2380.80 <br>
clflush size    : 64 <br>
cache_alignment : 64 <br>
address sizes   : 39 bits physical, 48 bits virtual <br>
power management: <br>

processor       : 1 <br>
vendor_id       : GenuineIntel <br>
cpu family      : 6 <br>
model           : 126 <br>
model name      : Intel(R) Core(TM) i5-1035G1 CPU @ 1.00GHz <br>
stepping        : 5 <br>
microcode       : 0xffffffff <br>
cpu MHz         : 1190.403 <br>
cache size      : 6144 KB <br>
physical id     : 0 <br>
siblings        : 2 <br>
core id         : 1 <br>
cpu cores       : 2 <br>
apicid          : 1 <br>
initial apicid  : 1 <br>
fpu             : yes <br>
fpu_exception   : yes <br>
cpuid level     : 22 <br>
wp              : yes <br>
flags           : fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush mmx fxsr sse sse2 ht syscall nx rdtscp lm constant_tsc rep_good nopl xtopology nonstop_tsc cpuid tsc_known_freq pni pclmulqdq ssse3 cx16 pcid sse4_1 sse4_2 movbe popcnt aes rdrand hypervisor lahf_lm abm 3dnowprefetch invpcid_single ibrs_enhanced fsgsbase bmi1 bmi2 invpcid rdseed clflushopt md_clear flush_l1d arch_capabilities <br>
bugs            : spectre_v1 spectre_v2 spec_store_bypass swapgs itlb_multihit srbds mmio_stale_data retbleed eibrs_pbrsb <br>
bogomips        : 2380.80 <br>
clflush size    : 64 <br>
cache_alignment : 64 <br>
address sizes   : 39 bits physical, 48 bits virtual <br>
power management: <br> </p>


<p> >> /proc   loadavg <br>
0.13 0.45 0.24 2/410 1889 <br></p>

<p> >> history <br>
/proc/cpuinfo <br>
/proc   loadavg <br>
>> /proc/1878/sched <br>
top (1878, #threads: 1) <br>
------------------------------------------------------------------- <br>
se.exec_start                                :        238046.869254 <br>
se.vruntime                                  :            32.097026 <br>
se.sum_exec_runtime                          :            10.474165 <br>
se.nr_migrations                             :                    0 <br>
nr_switches                                  :                    6 <br>
nr_voluntary_switches                        :                    4 <br>
nr_involuntary_switches                      :                    2 <br>
se.load.weight                               :              1048576 <br>
se.avg.load_sum                              :                39729 <br>
se.avg.runnable_sum                          :             25313140 <br>
se.avg.util_sum                              :             24217074 <br>
se.avg.load_avg                              :                  866 <br>
se.avg.runnable_avg                          :                  537 <br>
se.avg.util_avg                              :                  514 <br>
se.avg.last_update_time                      :         238046868480 <br>
se.avg.util_est.ewma                         :                  526 <br>
se.avg.util_est.enqueued                     :                  514 <br>
policy                                       :                    0 <br>
prio                                         :                  120 <br>
clock-delta                                  :                   88 <br>
mm->numa_scan_seq                            :                    0 <br>
numa_pages_migrated                          :                    0 <br>
numa_preferred_nid                           :                   -1 <br>
total_numa_faults                            :                    0 <br>
current_node=0, numa_group_id=0 <br>
numa_faults node=0 task_private=0 task_shared=0 group_private=0 group_shared=0 <br></p>

<p> >> /proc 1878/status <br>
Name:   top <br>
Umask:  0022 <br>
State:  T (stopped) <br>
Tgid:   1878 <br>
Ngid:   0 <br>
Pid:    1878 <br>
PPid:   1875 <br>
TracerPid:      0 <br>
Uid:    1000    1000    1000    1000 <br>
Gid:    1000    1000    1000    1000 <br>
FDSize: 256 <br>
Groups: 27 1000 <br>
NStgid: 1878 <br>
NSpid:  1878 <br>
NSpgid: 1878 <br>
NSsid:  1875 <br>
VmPeak:     9640 kB <br>
VmSize:     9544 kB <br>
VmLck:         0 kB <br>
VmPin:         0 kB <br>
VmHWM:      3368 kB <br>
VmRSS:      3368 kB <br>
RssAnon:             344 kB <br>
RssFile:            3024 kB <br>
RssShmem:              0 kB <br>
VmData:      628 kB <br>
VmStk:       132 kB <br>
VmExe:        76 kB <br>
VmLib:      4072 kB <br>
VmPTE:        60 kB <br>
VmSwap:        0 kB <br>
HugetlbPages:          0 kB <br>
CoreDumping:    0 <br>
THP_enabled:    1 <br>
Threads:        1 <br>
SigQ:   0/31758 <br>
SigPnd: 0000000000000000 <br>
ShdPnd: 0000000000000000 <br>
SigBlk: fffffffe7ffbfeff <br>
SigIgn: 0000000000000000 <br>
SigCgt: fffffffffffafeff <br>
CapInh: 0000000000000000 <br>
CapPrm: 0000000000000000 <br>
CapEff: 0000000000000000 <br>
CapBnd: 000001ffffffffff <br>
CapAmb: 0000000000000000 <br>
NoNewPrivs:     0 <br>
Seccomp:        0 <br>
Seccomp_filters:        0 <br>
Speculation_Store_Bypass:       vulnerable <br>
SpeculationIndirectBranch:      always enabled <br>
Cpus_allowed:   3 <br>
Cpus_allowed_list:      0-1 <br>
Mems_allowed: <br>   00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000000,00000001 <br>
Mems_allowed_list:      0 <br>
voluntary_ctxt_switches:        4 <br>
nonvoluntary_ctxt_switches:     2 <br></p>

<p> >> /proc /1878/environ <br>
SHELL=/bin/bashPWD=/home/sgomes2LOGNAME=sgomes2XDG_SESSION_TYPE=ttyMOTD_SHOWN=pamHOME=/home/sgomes2LANG=en_US.UTF- 8LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:SSH_CONNECTION=192.168.56.1 64025 192.168.56.101 22XDG_SESSION_CLASS=userTERM=vt100USER=sgomes2SHLVL=0XDG_SESSION_ID=4XDG_RUNTIME_DIR=/run/user/1000SSH_CLIENT=192.168.56.1 64025 22PATH=/usr/local/bin:/usr/bin:/bin:/usr/gamesDBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/busSSH_TTY=/dev/pts/2_=/usr/bin/top <br></p>
<p> >> ls <br>
main_template  main_template.c  main_template.o  Makefile  project1  README.md  simple_shell  simple_shell.c  simple_shell.o  utils.c  utils.h  utils.o <br></p>
<p> >> ls -al <br>
total 200 <br>
drwxr-xr-x  3 sgomes2 sgomes2  4096 Mar  8 14:05 . <br>
drwxr-xr-x 18 sgomes2 sgomes2  4096 Mar  8 14:05 .. <br>
-rwxr-xr-x  1 sgomes2 sgomes2 31344 Mar  8 14:05 main_template <br>
-rw-r--r--  1 sgomes2 sgomes2 18397 Mar  8 13:54 main_template.c <br>
-rw-r--r--  1 sgomes2 sgomes2 20864 Mar  8 14:05 main_template.o <br>
-rw-r--r--  1 sgomes2 sgomes2   846 Mar  8 14:09 Makefile <br>
drwxr-xr-x  3 sgomes2 sgomes2  4096 Mar  1 09:32 project1 <br>
-rw-r--r--  1 sgomes2 sgomes2  1174 Feb 23 10:05 README.md <br>
-rwxr-xr-x  1 sgomes2 sgomes2 31336 Mar  8 14:04 simple_shell <br>
-rw-r--r--  1 sgomes2 sgomes2 18396 Mar  8 13:54 simple_shell.c <br>
-rw-r--r--  1 sgomes2 sgomes2 20864 Mar  8 14:04 simple_shell.o <br>
-rw-r--r--  1 sgomes2 sgomes2  7714 Feb 23 10:05 utils.c <br>
-rw-r--r--  1 sgomes2 sgomes2  2330 Feb 23 10:05 utils.h <br>
-rw-r--r--  1 sgomes2 sgomes2 13984 Mar  5 21:18 utils.o <br></p>
<p> >> echo "Hello World" <br>
Hello World <br></p>
<p> >> /bin/echo Hello\nWorld <br>
Hello <br>
World <br></p>
<p> >> /bin/echo "Hello\\nWorld" <br>
Hello\\nWorld <br></p>
<p> >> history <br>
/proc   loadavg <br>
history <br>
/proc/1878/sched <br>
/proc 1878/status <br>
/proc /1878/environ <br>
ls <br>
ls -al <br>
echo "Hello World" <br>
/bin/echo Hello\nWorld <br>
/bin/echo "Hello\\nWorld" <br></p>
<p> >> ps <br>
    PID TTY          TIME CMD <br>
   1841 pts/1    00:00:00 bash <br>
   1874 pts/1    00:00:00 main_template <br>
   1902 pts/1    00:00:00 ps <br></p>
<p> >> ps -el <br>
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD <br>
4 S     0       1       0  0  80   0 - 24659 -      ?        00:00:01 systemd <br>
1 S     0       2       0  0  80   0 -     0 -      ?        00:00:00 kthreadd <br>
1 I     0       3       2  0  60 -20 -     0 -      ?        00:00:00 rcu_gp <br>
1 I     0       4       2  0  60 -20 -     0 -      ?        00:00:00 rcu_par_gp <br>
1 I     0       5       2  0  60 -20 -     0 -      ?        00:00:00 netns <br>
1 I     0       7       2  0  60 -20 -     0 -      ?        00:00:00 kworker/0:0H-events_highpri <br>
5 I     0       8       2  0  80   0 -     0 -      ?        00:00:00 kworker/u4:0-events_unbound <br>
1 I     0       9       2  0  60 -20 -     0 -      ?        00:00:01 kworker/0:1H-events_highpri <br>
1 I     0      10       2  0  60 -20 -     0 -      ?        00:00:00 mm_percpu_wq <br>
1 S     0      11       2  0  80   0 -     0 -      ?        00:00:00 rcu_tasks_rude_ <br>
1 S     0      12       2  0  80   0 -     0 -      ?        00:00:00 rcu_tasks_trace <br>
1 S     0      13       2  0  80   0 -     0 -      ?        00:00:00 ksoftirqd/0 <br>
1 I     0      14       2  0  80   0 -     0 -      ?        00:00:00 rcu_sched <br>
1 S     0      15       2  0 -40   - -     0 -      ?        00:00:00 migration/0 <br>
1 I     0      16       2  0  80   0 -     0 -      ?        00:00:01 kworker/0:1-events <br>
1 S     0      17       2  0  80   0 -     0 -      ?        00:00:00 cpuhp/0 <br>
1 S     0      18       2  0  80   0 -     0 -      ?        00:00:00 cpuhp/1 <br>
1 S     0      19       2  0 -40   - -     0 -      ?        00:00:00 migration/1 <br>
1 S     0      20       2  0  80   0 -     0 -      ?        00:00:00 ksoftirqd/1 <br>
1 I     0      21       2  0  80   0 -     0 -      ?        00:00:00 kworker/1:0-events <br>
1 I     0      22       2  0  60 -20 -     0 -      ?        00:00:00 kworker/1:0H-events_highpri <br>
1 I     0      24       2  0  80   0 -     0 -      ?        00:00:00 kworker/u4:1-events_unbound <br>
5 S     0      25       2  0  80   0 -     0 -      ?        00:00:00 kdevtmpfs <br>
1 I     0      26       2  0  60 -20 -     0 -      ?        00:00:00 inet_frag_wq <br>
1 S     0      27       2  0  80   0 -     0 -      ?        00:00:00 kauditd <br>
1 S     0      28       2  0  80   0 -     0 -      ?        00:00:00 khungtaskd <br>
1 S     0      29       2  0  80   0 -     0 -      ?        00:00:00 oom_reaper <br>
1 I     0      30       2  0  60 -20 -     0 -      ?        00:00:00 writeback <br>
1 S     0      31       2  0  80   0 -     0 -      ?        00:00:00 kcompactd0 <br>
1 S     0      32       2  0  85   5 -     0 -      ?        00:00:00 ksmd <br>
1 S     0      33       2  0  99  19 -     0 -      ?        00:00:00 khugepaged <br>
1 I     0      53       2  0  60 -20 -     0 -      ?        00:00:00 kintegrityd <br>
1 I     0      54       2  0  60 -20 -     0 -      ?        00:00:00 kblockd <br>
1 I     0      55       2  0  60 -20 -     0 -      ?        00:00:00 blkcg_punt_bio <br>
1 I     0      56       2  0  60 -20 -     0 -      ?        00:00:00 edac-poller <br>
1 I     0      57       2  0  60 -20 -     0 -      ?        00:00:00 devfreq_wq <br>
1 S     0      58       2  0  80   0 -     0 -      ?        00:00:00 kswapd0 <br>
1 I     0      59       2  0  60 -20 -     0 -      ?        00:00:00 kthrotld <br>
1 I     0      60       2  0  60 -20 -     0 -      ?        00:00:00 acpi_thermal_pm <br>
1 I     0      61       2  0  60 -20 -     0 -      ?        00:00:00 kworker/1:1H-events_highpri <br>
1 I     0      62       2  0  60 -20 -     0 -      ?        00:00:00 mld <br>
1 I     0      63       2  0  60 -20 -     0 -      ?        00:00:00 ipv6_addrconf <br>
1 I     0      64       2  0  80   0 -     0 -      ?        00:00:00 kworker/u4:2-flush-8:0 <br>
1 I     0      73       2  0  60 -20 -     0 -      ?        00:00:00 kstrp <br>
1 I     0      74       2  0  60 -20 -     0 -      ?        00:00:00 zswap-shrink <br>
1 I     0      75       2  0  60 -20 -     0 -      ?        00:00:00 kworker/u5:0 <br>
1 I     0     108       2  0  80   0 -     0 -      ?        00:00:00 kworker/0:2-events <br>
1 I     0     118       2  0  60 -20 -     0 -      ?        00:00:00 ata_sff <br>
1 S     0     119       2  0  80   0 -     0 -      ?        00:00:00 scsi_eh_0 <br>
1 I     0     120       2  0  60 -20 -     0 -      ?        00:00:00 scsi_tmf_0 <br>
1 S     0     121       2  0  80   0 -     0 -      ?        00:00:00 scsi_eh_1 <br>
1 I     0     122       2  0  60 -20 -     0 -      ?        00:00:00 scsi_tmf_1 <br>
1 S     0     123       2  0  80   0 -     0 -      ?        00:00:00 scsi_eh_2 <br>
1 I     0     124       2  0  60 -20 -     0 -      ?        00:00:00 scsi_tmf_2 <br>
1 I     0     128       2  0  60 -20 -     0 -      ?        00:00:00 ttm_swap <br>
1 S     0     129       2  0   9   - -     0 -      ?        00:00:00 irq/18-vmwgfx <br>
1 S     0     130       2  0   9   - -     0 -      ?        00:00:00 card0-crtc0 <br>
1 S     0     131       2  0   9   - -     0 -      ?        00:00:00 card0-crtc1 <br>
1 S     0     132       2  0   9   - -     0 -      ?        00:00:00 card0-crtc2 <br>
1 S     0     133       2  0   9   - -     0 -      ?        00:00:00 card0-crtc3 <br>
1 S     0     134       2  0   9   - -     0 -      ?        00:00:00 card0-crtc4 <br>
1 S     0     135       2  0   9   - -     0 -      ?        00:00:00 card0-crtc5 <br>
1 S     0     136       2  0   9   - -     0 -      ?        00:00:00 card0-crtc6 <br>
1 S     0     137       2  0   9   - -     0 -      ?        00:00:00 card0-crtc7 <br>
1 S     0     175       2  0  80   0 -     0 -      ?        00:00:00 jbd2/sda1-8 <br>
1 I     0     176       2  0  60 -20 -     0 -      ?        00:00:00 ext4-rsv-conver <br>
4 S     0     216       1  0  80   0 - 31975 -      ?        00:00:01 systemd-journal <br>
4 S     0     236       1  0  80   0 -  5344 -      ?        00:00:00 systemd-udevd <br>
4 S   105     284       1  0  80   0 - 22142 -      ?        00:00:00 systemd-timesyn <br>
1 I     0     296       2  0  80   0 -     0 -      ?        00:00:00 kworker/1:3-ata_sff <br>
4 S     0     333       1  0  80   0 - 59157 -      ?        00:00:00 accounts-daemon <br>
4 S   110     336       1  0  80   0 -  1832 -      ?        00:00:00 avahi-daemon <br>
4 S     0     337       1  0  80   0 -  1686 -      ?        00:00:00 cron <br>
4 S   104     338       1  0  80   0 -  2467 -      ?        00:00:01 dbus-daemon <br>
4 S     0     340       1  0  80   0 - 63691 -      ?        00:00:00 NetworkManager <br>
4 S     0     342       1  0  80   0 - 58986 -      ?        00:00:01 polkitd <br>
4 S     0     343       1  0  80   0 - 55199 -      ?        00:00:00 rsyslogd <br>
4 S     0     344       1  0  80   0 - 58210 -      ?        00:00:00 switcheroo-cont <br>
4 S     0     345       1  0  80   0 -  5529 -      ?        00:00:00 systemd-logind <br>
4 S     0     347       1  0  80   0 - 98441 -      ?        00:00:00 udisksd <br>
4 S     0     352       1  0  80   0 -  3654 -      ?        00:00:00 wpa_supplicant <br>
1 S   110     354     336  0  80   0 -  1787 -      ?        00:00:00 avahi-daemon <br>
4 S     0     377       1  0  80   0 - 78710 -      ?        00:00:00 ModemManager <br>
4 S     0     401       1  0  80   0 -  6758 -      ?        00:00:00 cupsd <br>
4 S     0     412       1  0  80   0 - 29695 -      ?        00:00:00 unattended-upgr <br>
4 S     0     438       1  0  80   0 - 43807 -      ?        00:00:00 cups-browsed <br>
4 S     0     450       1  0  80   0 - 59922 -      ?        00:00:00 gdm3 <br>
4 S     0     452       1  0  80   0 -  3338 -      ?        00:00:00 sshd <br>
4 S   108     639       1  0  81   1 - 38437 -      ?        00:00:00 rtkit-daemon <br>
5 S   117     828       1  0  80   0 -  4683 -      ?        00:00:00 exim4 <br>
4 S     0     853       1  0  80   0 - 61769 -      ?        00:00:00 upowerd <br>
4 S     0     923       1  1  80   0 - 109493 -     ?        00:00:04 packagekitd <br>
4 S   114    1052       1  0  80   0 - 60732 -      ?        00:00:00 colord <br>
4 S     0    1120     450  0  80   0 - 41676 -      ?        00:00:00 gdm-session-wor <br>
4 S  1000    1125       1  0  80   0 -  3949 -      ?        00:00:00 systemd <br>
5 S  1000    1126    1125  0  80   0 - 25411 -      ?        00:00:00 (sd-pam) <br>
0 S  1000    1140    1125  0  69 -11 - 22657 -      ?        00:00:00 pipewire <br>
0 S  1000    1142    1125  0  69 -11 - 223482 -     ?        00:00:00 pulseaudio <br>
0 S  1000    1144    1125  0  99   - - 127390 -     ?        00:00:00 tracker-miner-f <br>
0 S  1000    1146    1125  0  80   0 -  2334 -      ?        00:00:00 dbus-daemon <br>
1 S  1000    1152       1  0  80   0 - 59357 -      ?        00:00:00 gnome-keyring-d <br>
0 S  1000    1157    1125  0  80   0 - 59240 -      ?        00:00:00 gvfsd <br>
4 S  1000    1170    1120  0  80   0 - 39724 -      tty2     00:00:00 gdm-wayland-ses <br>
0 S  1000    1175    1170  0  80   0 - 74513 -      tty2     00:00:00 gnome-session-b <br>
0 S  1000    1181    1125  0  80   0 - 94996 -      ?        00:00:00 gvfsd-fuse <br>
0 S  1000    1185    1125  0  80   0 - 87276 -      ?        00:00:00 gvfs-udisks2-vo <br>
0 S  1000    1213    1125  0  80   0 - 58233 -      ?        00:00:00 gvfs-mtp-volume <br>
0 S  1000    1218    1125  0  80   0 - 77905 -      ?        00:00:00 gvfs-afc-volume <br>
0 S  1000    1223    1125  0  80   0 - 58281 -      ?        00:00:00 gvfs-goa-volume <br>
0 S  1000    1227    1125  0  80   0 - 142546 -     ?        00:00:00 goa-daemon <br>
0 S  1000    1248    1125  0  80   0 - 77962 -      ?        00:00:00 goa-identity-se <br>
0 S  1000    1249    1140  0  69 -11 - 21339 -      ?        00:00:00 pipewire-media- <br>
0 S  1000    1250    1125  0  80   0 - 22058 -      ?        00:00:00 gnome-session-c <br>
0 S  1000    1252    1125  0  80   0 -  1506 -      ?        00:00:00 ssh-agent <br>
0 S  1000    1255    1125  0  80   0 - 181147 -     ?        00:00:00 gnome-session-b <br>
0 S  1000    1263    1125  0  80   0 - 58792 -      ?        00:00:00 gvfs-gphoto2-vo <br>
0 S  1000    1287    1125  1  80   0 - 965819 -     ?        00:00:05 gnome-shell <br>
0 S  1000    1291    1255  0  80   0 - 76836 -      ?        00:00:00 at-spi-bus-laun <br>
0 S  1000    1300    1291  0  80   0 -  2057 -      ?        00:00:00 dbus-daemon <br>
0 S  1000    1324    1287  0  80   0 - 187585 -     ?        00:00:00 Xwayland <br>
0 S  1000    1344    1125  0  80   0 - 58212 -      ?        00:00:00 xdg-permission- <br>
0 S  1000    1348    1125  0  80   0 - 145240 -     ?        00:00:00 gnome-shell-cal <br>
0 S  1000    1355    1125  0  80   0 - 98232 -      ?        00:00:00 evolution-sourc <br>
0 S  1000    1362    1125  0  80   0 - 210267 -     ?        00:00:00 evolution-calen <br>
0 S  1000    1366    1125  0  80   0 - 633717 -     ?        00:00:00 gjs <br>
0 S  1000    1368    1125  0  80   0 - 41431 -      ?        00:00:00 at-spi2-registr <br>
0 S  1000    1372    1125  0  80   0 - 76728 -      ?        00:00:00 gsd-a11y-settin <br>
0 S  1000    1378    1125  0  80   0 - 112712 -     ?        00:00:00 gsd-color <br>
0 S  1000    1379    1125  0  80   0 - 94047 -      ?        00:00:00 gsd-datetime <br>
0 S  1000    1381    1125  0  80   0 - 77231 -      ?        00:00:00 gsd-housekeepin <br>
0 S  1000    1382    1125  0  80   0 - 85520 -      ?        00:00:00 gsd-keyboard <br>
0 S  1000    1383    1125  0  80   0 - 161149 -     ?        00:00:00 gsd-media-keys <br>
0 S  1000    1390    1125  0  80   0 - 112569 -     ?        00:00:00 gsd-power <br>
0 S  1000    1393    1255  0  80   0 - 230336 -     ?        00:00:03 gnome-software <br>
0 S  1000    1398    1255  0  80   0 - 169213 -     ?        00:00:00 evolution-alarm <br>
0 S  1000    1399    1125  0  80   0 - 61658 -      ?        00:00:00 gsd-print-notif <br>
0 S  1000    1408    1125  0  80   0 - 113582 -     ?        00:00:00 gsd-rfkill <br>
0 S  1000    1413    1125  0  80   0 - 58190 -      ?        00:00:00 gsd-screensaver <br>
0 S  1000    1414    1125  0  80   0 - 115565 -     ?        00:00:00 gsd-sharing <br>
0 S  1000    1424    1125  0  80   0 - 78145 -      ?        00:00:00 gsd-smartcard <br>
0 S  1000    1430    1125  0  80   0 - 79889 -      ?        00:00:00 gsd-sound <br>
0 S  1000    1431    1125  0  80   0 - 95540 -      ?        00:00:00 gsd-usb-protect <br>
0 S  1000    1433    1125  0  80   0 - 104028 -     ?        00:00:00 gsd-wacom <br>
0 S  1000    1442    1255  0  80   0 - 57963 -      ?        00:00:00 gsd-disk-utilit <br>
0 S  1000    1457    1125  0  80   0 - 38985 -      ?        00:00:00 dconf-service <br>
0 S  1000    1464    1125  0  80   0 - 185460 -     ?        00:00:00 evolution-addre <br>
0 S  1000    1496    1125  0  80   0 - 86216 -      ?        00:00:00 gsd-printer <br>
0 S  1000    1546    1287  0  80   0 - 114644 -     ?        00:00:00 ibus-daemon <br>
0 S  1000    1550    1125  0  80   0 - 267929 -     ?        00:00:00 gsd-xsettings <br>
0 S  1000    1557    1546  0  80   0 - 39991 -      ?        00:00:00 ibus-memconf <br>
0 S  1000    1558    1546  0  80   0 - 86509 -      ?        00:00:01 ibus-extension- <br>
0 S  1000    1566    1125  0  80   0 - 48420 -      ?        00:00:00 ibus-x11 <br>
0 S  1000    1570    1125  0  80   0 - 58442 -      ?        00:00:00 ibus-portal <br>
0 S  1000    1607    1546  0  80   0 - 39990 -      ?        00:00:00 ibus-engine-sim <br>
4 S     0    1613       1  0  80   0 - 95497 -      ?        00:00:00 fwupd <br>
0 S  1000    1677    1125  0  80   0 - 201618 -     ?        00:00:00 gnome-calendar <br>
0 S  1000    1681    1125  0  80   0 - 185464 -     ?        00:00:00 seahorse <br>
0 S  1000    1683    1125  0  80   0 - 100139 -     ?        00:00:00 gnome-terminal- <br>
0 S  1000    1711    1157  0  80   0 - 77768 -      ?        00:00:00 gvfsd-trash <br>
0 S  1000    1756    1683  0  80   0 -  2044 -      pts/0    00:00:00 bash <br>
0 S  1000    1806    1157  0  80   0 - 77675 -      ?        00:00:00 gvfsd-burn <br>
4 S     0    1830     452  0  80   0 -  3641 -      ?        00:00:00 sshd <br>
5 R  1000    1839    1830  0  80   0 -  3692 -      ?        00:00:00 sshd <br>
0 S  1000    1841    1839  0  80   0 -  2050 -      pts/1    00:00:00 bash <br>
0 S  1000    1844    1839  0  80   0 -  1470 -      ?        00:00:00 sftp-server <br>
0 S  1000    1858    1125  0  80   0 - 39855 -      ?        00:00:00 gvfsd-metadata <br>
0 S  1000    1874    1841  0  80   0 -   592 -      pts/1    00:00:00 main_template <br>
0 S  1000    1875    1839  0  80   0 -  2050 -      pts/2    00:00:00 bash <br>
0 T  1000    1878    1875  0  80   0 -  2386 -      pts/2    00:00:00 top <br>
1 I     0    1899       2  0  80   0 -     0 -      ?        00:00:00 kworker/1:1-ata_sff <br>
0 R  1000    1903    1874  0  80   0 -  2419 -      pts/1    00:00:00 ps <br></p>
<p> >> exit 4 </p>

*Run in user terminal to check exit value* <br>
$ echo $? <br>
4

## Specifications:

*To exit the program, [exit] must be run in lowercase. [exit] accepts one argument, it can be an integer or string. If it is a string argument, the program will not exit and will continue. [/proc] filesystem commands can be run in these manners: [/proc [space]/[command]], [/proc/[command]], [/proc [space][command]],[/proc/pid/[command]], [/proc [space]pid/[command]], [/proc [space]/pid/[command]]. If user runs command such as ["echo hello world"] it will be rejected as the program is interpreting that input as a string input and not a valid command. All other Linux commands without quotes will be executed correctly, if not referred to as a string. If PID for top & does not display valid output, run 'cd /proc' then 'ls' and use the following PIDs to see the designated output.*
