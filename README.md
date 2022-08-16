# Rev-Bin
## Task 2 - Programming Club - Secrectary Recruitment 2022-23

```Made By - Kartik Anant Kulkarni (210493)```

+ Tools Used:
    + IDA Freeware to visualise graphically the object-code in simple control structure and guess the PasswordLocation.
    + linux tools to generate `hexoutput.txt` and `ObjectDumpData.txt` from the binary.
+ Although the exact password was not found out, due to time constraints, following facts were observed:
    + Password is of length 30 characters.
    + The location is stored in the place as depicted in `PasswordLocation.jpg` (in hex), although encrypted.
    + Encoded input and corresponding comparion with the stored password was predicted from the control flow graph and the logic I found out is written in `DeducedCode.c`.