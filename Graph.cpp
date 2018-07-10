#include<bits/stdc++.h>


class Graph{
	private:
		class List{
	public:
		int data;
		List *next;
		std::string color;
		int dis;
		int discovery, finishing;
		List *par;
		List(int dat=0, List *nex= 0){
			data=dat;
			next=nex;
		}
};
		int v;
		int time;
		std::vector<List*> adj;
	public:
		Graph(int ver){
			v=ver;
			takeIn(v);
		}
		void takeIn(int v);
		void adjList(int ver);
		void BFS(Graph G, int s);
		void DFS(Graph G);
		void DFSVisit(Graph G, List* u);
		void prin(int s);
};

void Graph::prin(int s){
	List* m=adj[s];
	while(m){
		std::cout<<m->data<<" ";
		m=m->next;
	}
	std::cout<<std::endl;
}

void Graph::takeIn(int v){
	for(int i=1;i<=v;i++)
	adjList(i);
}

void Graph::adjList(int ver){
	List* root=new List();
	std::cout<<"Enter the number of vertices adjacent to vertex "<<ver<<std::endl;
	int n;
	std::cin>>n;
	std::cout<<"Enter the vertices adjacent to vertex "<<ver<<std::endl;
	int dat;
	std::cin>>dat;
	root->data=dat;
	root->next=0;
	List* nex=root;
	root->next=nex;
	while(--n){
		std::cin>>dat;
		List* n=new List();
		n->data=dat;
		n->next=0;
		nex->next=n;
		nex=nex->next;
	}
	adj.push_back(root);
}

void Graph::BFS(Graph G, int s){
	std::vector<List*>::iterator it=adj.begin();
	for(;it!=adj.end();++it){
		List* m=*it;
	while(m){
		m->color="White";
		m->par=0;
		m->dis=INT_MAX;
		m=m->next;
	}
	}
	List* r=adj[s];
	r->color="Gray";
	r->dis=0;
	r->par=0;
	std::queue<List*> q;
	q.push(r);
	while(!q.empty()){
		List* u=q.front();
		q.pop();
		List* v=adj[u->data];
		while(v){
			if(v->color=="White"){
				v->color="Gray";
				v->dis=u->dis +1;
				v->par=u;
				q.push(v);
			}
		}
		v->color="Black";
	}
	
}
void Graph::DFS(Graph G){
	std::vector<List*>::iterator it=adj.begin();
	for(;it!=adj.end();++it){
		List* m=*it;
	while(m){
		m->color="White";
		m->par=0;
		m=m->next;
	}
	}
	time=0;
	for(it=adj.begin();it!=adj.end();++it){
		List *u=*it;
		if(u->color=="White")
		DFSVisit(G, u);
	}
}
void Graph::DFSVisit(Graph G, List* u){
	time+=1;
	u->discovery=time;
	u->color="Grey";
	List* v=adj[u->data];
	while(v){
		if(v->color=="White"){
			v->par=u;
			DFSVisit(G, v);}
		u->color="Black";
		time+=1;
		u->finishing=time;
		}
}
int main(){
	int ver;
	std::ios::sync_with_stdio(false);
	std::cout<<"Enter the number of vertices\n";
	std::cin>>ver;
	Graph m(ver);
	std::cout<<"Enter the source vertex to start the BFS\n";
	int s;
	std::cin>>s;
	m.BFS(m, s);
	return 0;
}
