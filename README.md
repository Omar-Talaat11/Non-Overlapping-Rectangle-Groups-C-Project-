# Non-Overlapping-Rectangle-Groups-C-Project-

1 - Platform used: Linux

2 – Flow chart:


![image](https://github.com/user-attachments/assets/320fcc33-ea62-451d-a304-2e120677c845)


3 – Pseudocode:

for each line in the input file:
    read the line
    construct a Rectangle object from the line (x1, y1, x2, y2)
    add the rectangle to the list: rectangles[]

Step 2: Group Rectangles into Non-Overlapping Sets
for each rectangle in rectangles[]:
    added_to_group = false

    for each group in groups[]:
        if rectangle does not overlap with any rectangle in this group:
            add the rectangle to this group
            added_to_group = true
            break

    if rectangle was not added to any group:
        create a new group
        add the rectangle to this new group
        append the new group to groups[]

Step 3: Write Each Group to a Separate Output File
for each group in groups[]:
    create a new output file
    write all rectangles in this group to the file (using same input format)




4 – Results:
| Dataset           | # Inputs | # Output Groups | Runtime (sec) | Memory (MB) |
| ----------------- | -------- | --------------- | ------------- | ----------- |
| data\_set\_1.txt  | 5        | 1               | 0.00031       | 3.492       |
| data\_set\_2.txt  | 7        | 2               | 0.00117       | 3.508       |
| data\_set\_3.txt  | 20       | 3               | 0.00053       | 3.516       |
| data\_set\_4.txt  | 39       | 3               | 0.00084       | 3.528       |
| data\_set\_5.txt  | 77       | 4               | 0.00128       | 3.536       |
| data\_set\_6.txt  | 136      | 5               | 0.00175       | 3.540       |
| data\_set\_7.txt  | 216      | 5               | 0.00254       | 3.560       |
| data\_set\_8.txt  | 460      | 6               | 0.00735       | 3.592       |
| data\_set\_9.txt  | 741      | 12              | 0.01685       | 3.612       |
| data\_set\_10.txt | 981      | 6               | 0.03653       | 3.688       |
| data\_set\_11.txt | 5793     | 7               | 0.87126       | 3.900       |
| data\_set\_12.txt | 6775     | 7               | 1.16632       | 4.016       |
| data\_set\_13.txt | 7538     | 7               | 1.54299       | 3.968       |
| data\_set\_14.txt | 8774     | 7               | 2.02688       | 4.124       |
| data\_set\_15.txt | 9188     | 7               | 2.09198       | 4.224       |


5 – Testing methodology:
  Testing each step of the algorithm through logging the data at this step or sometimes printing flags indicating reaching this point in the algorithm.
  Testing final results through creating another code that takes the output of the main code as input and validate the non-overlapping condition for each group separately.

6 – Screenshots: 


![image](https://github.com/user-attachments/assets/c45086f6-72d4-4634-9486-ecea0ab221d1)
![image](https://github.com/user-attachments/assets/a3a54666-959d-4f2b-a43f-b59c9f467e60)
![image](https://github.com/user-attachments/assets/7597de97-a46b-4088-abb6-a8bf559c5c08)
