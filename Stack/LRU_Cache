class Node{
    public:
    int key,val;
    Node*next=NULL;Node*prev=NULL;
    Node(int k,int v){
        key=k;
        val=v;
    }
};
class LRUCache {
public:
    int cap;unordered_map<int,Node*>m;
    Node*head;
    Node*tail;

    LRUCache(int capacity) {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
         head->next=tail;
         tail->prev=head;
         cap=capacity;
    }
   
    void AddAfterHead(Node*n){
        if(n!=NULL){
        n->prev=head;
        n->next=head->next;
        head->next->prev=n;
        head->next=n;}
    }
    void remove(Node*n){   //Node only not value
        n->prev->next=n->next;
        n->next->prev=n->prev;
        n->next=NULL;
        n->prev=NULL;
    }
    
    
    int get(int key) {
        if(m.find(key)==m.end())return -1;
        else{
            int ans=m[key]->val;
            remove(m[key]);
            AddAfterHead(m[key]);
            return ans;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key]->val=value;
            remove(m[key]);
            AddAfterHead(m[key]);
        }
        else{
            Node*n=new Node(key,value);
           
            if(m.size()<cap){
                m[key]=n;
                 AddAfterHead(n);
            }
            else{
                Node*byebye=tail->prev;
                m.erase(byebye->key);
                tail->prev=tail->prev->prev;
                tail->prev->next=tail;
                delete byebye;
                 AddAfterHead(n);
                 m[key]=n;
            }
        }  
    } 
};
