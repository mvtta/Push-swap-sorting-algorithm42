<h2 align="center">
Push Swap

</h2>
<h6 align="center">
sort data on a stack, with a limited set of instructions,  
using the lowest possible number of actions 📚. 
<br>
status: ongoing
<br>
by: mvaldeta
</h6>

<h2>
</h2>

|  |  |  |
|:---------:|:---------:|:---------:|
|![STACK3](https://64.media.tumblr.com/ac866c7d72f6f3a3958ae1a238038d88/tumblr_nyaxxsIIaQ1qblxj7o7_400.gifv)|![STACK3](https://64.media.tumblr.com/bcf49029014e8bbecf72e9c4a4ab6337/tumblr_nyaxxsIIaQ1qblxj7o3_400.gifv)|![STACK3](https://64.media.tumblr.com/84fbd5ff5b0a41347f7ad9de95dd534e/tumblr_nyaxxsIIaQ1qblxj7o10_400.gifv)|

###### Rules  
```
Create a ~Fast~ sorting algorithm with two stacks: A + B  
To do so, you only have the following operations at your disposal:  
```
- SA  : swaps the TOP 2 elements of A 🔄    
- SB  : swaps the TOP 2 elements of B 🔄    
- SS  : SA and SB at the same time  A🔄 B🔄 TOPS
- PA  : TOP A -> TOP B ➡️ 
- PB  : TOP B -> TOB A ⬅️
- RA  : rotates A ⤵️
- RB  : rotates B ⤵️ 
- RR  : rotates A ⤵️ + rotates B ⤵️ at the same time.
- RRA : rotates A ⤴️ 
- RRA : rotates B ⤴️  
- RRR : rotates A ⤴️ + rotates B ⤴️ at the same time.  

###### Approach  
```
It's not implemented yet, but my idea is to divide into stack_a && stack_b even and uneven numbers. 
According to the n-elements on each stack:  
1) While first B > first A : Rotate & Push B:TOP -> A:END
2) Then, pass even to B && uneven to A
repeat step 1 & 2 until stack b is left with n <= 2
3) Check pseudo sort for A
4) Pass unsorted to B

Generic conditions fort state "sorted"
n1 + n2 <= n3

if this happens Push into the other stack

Generic conditions for intructions to happen
SA  -> first A > second A
SB  -> first B > second B
SS  -> SA && SB == true
PA  -> first A > first B
PB  -> first B < first A 
RA  -> first A > last B
RB  -> first B > last A
RR  -> RA && RB  == true
RRA -> last A < first B
RRB -> last B < first A
RRR -> RRA && RRB == true || NONE of the conditions are true to restart the cycle
```

###### Illustration 

| stack A | stack B |
|:---------:|:-----------------:|
| 83 |    |
| 31 |    |
| 19 |    |
| 52 |    |
| 82 |    |
| 96 |    |
| 66 |    |
| 23 |    |
| 34 |    |
| 4  |    | 
###### start

###### Line of thought
```
loading
```

###### Research  

[Personal Log](https://docs.google.com/document/d/1BRx4uDb469BFj6pL2ozEluOIOzOkLMNUBLTMFMG50CU/edit?usp=sharing)  

[Peek](https://en.wikipedia.org/wiki/Peek_(data_type_operation))   

[Abtract data types](https://en.wikipedia.org/wiki/Abstract_data_type)

[Linus on Linked lists](https://github.com/mkirchner/linked-list-good-taste)  

