//Editorial: https://youtu.be/K5pcpkEMCN0
//  This problem has a pre-requisite problem that must be solved 
//and it is present in LeetCode(Implement Trie (Prefix Tree)) as well as in codestudio alse. 
//The solution of that problem is available on my LeetCode repository.
struct Node{
    Node* links[26];
//     bool flag=false;
    int cntend=0,cntpre=0;
    bool containskey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    Node* getnode(char ch)
    {
        return links[ch-'a'];
    }
    void putnode(char ch,Node *temp)
    {
        links[ch-'a']=temp;
    }
    void increaseend()
    {
        cntend++;
    }
    void increasepre()
    {
        cntpre++;
    }
    void deleteend()
    {
        cntend--;
    }
    void reduce()
    {
        cntpre--;
    }
    int getend()
    {
        return cntend;
    }
    int getpre()
    {
        return cntpre;
    }
};
Node* root;
class Trie{

    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containskey(word[i]))
                temp->putnode(word[i],new Node());
            temp=temp->getnode(word[i]);
            temp->increasepre();
        }
        temp->increaseend();
    }
    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->containskey(word[i]))
                temp=temp->getnode(word[i]);
            else
                return 0;
        }
        return temp->getend();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->containskey(word[i]))
                temp=temp->getnode(word[i]);
            else
                return 0;
        }
        return temp->getpre();
    }

    void erase(string &word){
        // Write your code here.
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->containskey(word[i]))
            {
                temp=temp->getnode(word[i]);
                temp->reduce();
            }
            else
                return;
        }
        temp->deleteend();
    }
};
