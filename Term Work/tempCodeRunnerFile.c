
            elapasedTime+=curr->remainingTime;
            printf("Process %d completed in %dns\n",curr->id,elapasedTime);
                Process *temp=curr;
                curr=curr->next;
                if(curr==head){
                    break;
                }
                curr->count++;