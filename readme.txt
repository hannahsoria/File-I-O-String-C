CS333 - Project #6 - README
Hannah Soria
04/25/24

Directory Layout:
Project5_hmsori25/
|
|__/linkedlist.c
|__/linkedlist.h
|__/task1.c
|__/task2a.c
|__/task2b.c
|__/task2c.c
|__/task1swift.swift
|__/task2swift.swift
|__/task3swift.swift
|__/wctest.txt
|__/output.txt
|__/haiku.swift
|__/haiku.txt

linkedlist.c doesn't compile and run alone
linkedlist.h doesn't compile and run alone
wctest.txt doesn't compile and run alone
output.txt doesn't compile and run alone
haiku.txt doesn't compile and run alone

task1.c
 Compile:
	gcc -o task1 task1.c 
 Run:
	./task1 wctest.txt
 Output:

  Word: the                Frequency: 17
  Word: of                 Frequency: 7
  Word: and                Frequency: 6
  Word: was                Frequency: 5
  Word: with               Frequency: 4
  Word: a                  Frequency: 3
  Word: in                 Frequency: 3
  Word: central            Frequency: 2
  Word: portion            Frequency: 2
  Word: were               Frequency: 2
  Word: broken             Frequency: 2
  Word: but                Frequency: 2
  Word: up                 Frequency: 2
  Word: had                Frequency: 2
  Word: been               Frequency: 2
  Word: building           Frequency: 1
  Word: grey,              Frequency: 1
  Word: lichen-blotched            Frequency: 1
  Word: stone,             Frequency: 1
  Word: high               Frequency: 1
   
task2a.c
 Compile:
	gcc -o task2a task2a.c
 Run:
	./task2a
 Output:
 
  *after ^c then
  Interrupted!

 task2b.c
 Compile:
	gcc -o task2b task2b.c
 Run:
	./task2b
 Output:
   Floating Point Exception!

task2c.c
 Compile:
	gcc -o task2c task2c.c
 Run:
	./task2c
 Output:
   Seqmentation Fault!

task1swift.swift
 Compile:
	swiftc task1swift.swift -o task1swift_executable
 Run:
	./task1swift_executable wctest.txt 
 Output:

   Word:the                Frequency: 17
   Word:of                 Frequency: 7
   Word:and                Frequency: 6
   Word:was                Frequency: 5
   Word:with               Frequency: 4
   Word:in                 Frequency: 4
   Word:windows            Frequency: 3
   Word:a                  Frequency: 3
   Word:were               Frequency: 2
   Word:portion            Frequency: 2
   Word:been               Frequency: 2
   Word:up                 Frequency: 2
   Word:had                Frequency: 2
   Word:central            Frequency: 2
   Word:wings              Frequency: 2
   Word:broken             Frequency: 2
   Word:but                Frequency: 2
   Word:picture            Frequency: 1
   Word:this               Frequency: 1
   Word:our                Frequency: 1

task2swift.swift
 Compile:
	swiftc task2swift task2swift.swift
 Run:
	./task2swift
 Output:

   The building was of grey, lichen-blotched stone, with a high central portion and two curving wings, like the claws of a crab, thrown out on each side. In one of these wings the windows were broken and blocked with wooden boards, while the roof was partly caved in, a picture of ruin. The central portion was in little better repair, but the right-hand block was comparatively modern, and the blinds in the windows, with the blue smoke curling up from the chimneys, showed that this was where the family resided. Some scaffolding had been erected against the end wall, and the stone-work had been broken into, but there were no signs of any workmen at the moment of our visit. Holmes walked slowly up and down the ill-trimmed lawn and examined with deep attention the outsides of the windows. 

   write to file was successful
   hello, what is your name?
   *enter name in command line*
   nice to meet you, *whatever was entered*

task3swift.swift
 Compile:
	swiftc task3swift task3swift.swift
 Run:
	./task3swift
 Output:
   Error: no file found
   file write successful

haiku.swift
 Compile:
	swiftc haiku haiku.swift
 Run:
	./haiku
 Output:

  oh, FileHandle?
  and the FileManager
  so helpful to me!
