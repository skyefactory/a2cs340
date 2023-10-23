
<h1>Implementation of a min-max heap for CS340<h1>
<b>Dylan Ostapa - #20046307</b>

<h2>Features</h2></br>
<ul>
    <li>buildHeap - Takes a integer pointer and the number of elements. Inserts elements and maintains heap order. Outputs each insert step</li>
    <li>findMin and findMax - findMin returns the element at the root of the heap, findMax returns the maximum element , located in the roots direct children</li>
    <li>deleteMin and deleteMax - Uses the trickleDown algorithm  provided in the paper. Swaps the to be deleted element with the last element -> reduce size by one -> trickleDown where swap occured</li>
    <li>insert - Takes a value x, and inserts it at the end of the heap. uses the bubbleUp algorithm provided in the paper. </li>
</ul>
<h2>Instructions</h2>
    1: Extract Folder </br>
    2: Open folder in terminal </br>
    3: run 'make' command </br>
    4: run the resulting assign2dfo301 file</br>