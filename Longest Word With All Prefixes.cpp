//Editorial: https://youtu.be/AWnBa91lThI

struct Node{
    Node* links[26];
    bool flag=false;
    bool containskey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    Node* getnode(char ch)
    {
        return links[ch-'a'];
    }
    void putnode(char ch,Node* temp)
    {
		links[ch-'a']=temp;        
    }
    void setend()
    {
        flag=true;
    }
    bool isend()
    {
        return flag;
    }
};
class Trie{
    private:
    Node *root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(string word)
    {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containskey(word[i]))
                temp->putnode(word[i],new Node());
            temp=temp->getnode(word[i]);
        }
        temp->setend();
    }
    bool checkallprefixes(string word)
    {
        Node* temp=root;
        bool flag=true;
        for(int i=0;i<word.size();i++)
        {
            if(temp->containskey(word[i]))
            {
                temp=temp->getnode(word[i]);
                if(temp->isend()==false)
                    return false;
            }
            else
                return false;
        }
        return flag;
    }
};
string completeString(int n, vector<string> &a){
    Trie* obj=new Trie();
    for(auto it:a)
        obj->insert(it);
    string longest="";
    for(auto it:a)
    {
        if(obj->checkallprefixes(it))
        {
            if(it.size()>longest.size())
                longest=it;
            else if(it.size()==longest.size() and it<longest)
                longest=it;
        }
    }
    if(longest=="")
        return "None";
    return longest;
}
