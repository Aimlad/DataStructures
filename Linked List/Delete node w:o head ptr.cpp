//Delete node without head ptr

void deleteNode(Node *node)
{
   // Your code here
   *(node)=*(node->next);

}
