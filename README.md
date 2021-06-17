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
|:---------:|:-----------------:|
| |![IMG_COVER](https://64.media.tumblr.com/bcf49029014e8bbecf72e9c4a4ab6337/tumblr_nyaxxsIIaQ1qblxj7o3_400.gifv)| |

###### Rules  
```
Create a ~Fast~ sorting algorithm with two stacks: A + B  
To do so, you only have the following operations at your disposal:  
```
- SA : swaps the TOP 2 elements of A 🔄    
- SB : swaps the TOP 2 elements of B 🔄    
- SS : SA and SB at the same time  A🔄 B🔄 TOPS
- PA : TOP B -> TOP A (does nothing if b is empty) ⬅️
- PB : TOP A -> TOB B (does nothing if a is empty) ➡️
- RA : rotates A ⤵️
- RB : rotates B ⤵️ 
- RR : rotates A ⤵️ + rotates B ⤵️ at the same time.
- RRA : rotates A ⤴️ 
- RRA : rotates B ⤴️  
- RRR : otates A ⤴️ + rotates B ⤴️ at the same time.  

###### Approach  
```
It's not implemented yet, but my idea is to divide into stack_a && stack_b even and uneven numbers. 
According to the n-elements on each stack:  
1) While first B > first A : Rotate & Push B:TOP -> A:END
2) Then, pass even to B && uneven to A
repeat step 1 & 2 until stack b is left with n <= 2
3) Check pseudo sort for A
4) Pass unsorted to B
```

###### Illustration 

| stack A | stack B |
|:---------:|:-----------------:|
| 8 | 9 |
| 2 | 3 |
| 4 | 1 |
| 0 | 5 |
| 6 | 7 |

| stack A | stack B |
|:---------:|:-----------------:|
| 8 | 3 |
| 2 | 1 |
| 4 | 5 |
| 0 | 7 |
| 6 |
| 9 |

| stack A | stack B |
|:---------:|:-----------------:|
| 3 | 8 |
| 1 | 2 |
| 5 | 4 |
| 7 | 0 |
| 9 | 6 |

| stack A | stack B |
|:---------:|:-----------------:|
| 3 | 2 |
| 1 | 0 |
| 5 |   |
| 7 |   |
| 9 |   |
| 8 |   |
| 4 |   |
| 6 |   |


| stack A | stack B |
|:---------:|:-----------------:|
| 0 |   |
| 2 |   |
| 3 |   |
| 1 |   |
| 5 |   |
| 7 |   |
| 9 |   |
| 8 |   |
| 4 |   |
| 6 |   |

| stack A | stack B |
|:---------:|:-----------------:|
| 0 | 1 |
| 2 | 9 |
| 3 |   |
| 5 |   |
| 7 |   |
| 8 |   |
| 4 |   |
| 6 |   |

| stack A | stack B |
|:---------:|:-----------------:|
| 1 | 4 |
| 0 | 6 |
| 2 |   |
| 3 |   |
| 5 |   |
| 7 |   |
| 8 |   |
| 1 |   |
| 9 |   |

| stack A | stack B |
|:---------:|:-----------------:|
| 1 |   |
| 0 |   |
| 2 |   |
| 3 |   |
| 5 |   |
| 4 |   |
| 6 |   |
| 7 |   |
| 8 |   |
| 1 |   |
| 9 |   |



###### Line of thought
```
find largest on stack b, see how many positions is away from both-ends
if less than 2 positions swap and rotate push
```

###### Research  

[Personal Log](https://docs.google.com/document/d/1BRx4uDb469BFj6pL2ozEluOIOzOkLMNUBLTMFMG50CU/edit?usp=sharing)  

[Peek](https://en.wikipedia.org/wiki/Peek_(data_type_operation))   

[Abtract data types](https://en.wikipedia.org/wiki/Abstract_data_type)

[Linus on Linked lists](https://github.com/mkirchner/linked-list-good-taste)  

