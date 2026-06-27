Node * SwapPairs(Node*head){
        if(head==NULL || head->next==NULL)return head;

        Node * first = head ;
        Node * second = head->next ;
        Node *prev = NULL;
        while(first!=NULL && second!=NULL){
            first->next = second->next;
            second->next=first;
            if(prev==NULL){
                head =second;
            }else{
                prev->next=second;
            }
            prev = first ;
            prev->next=first->next;
        }
        return head;