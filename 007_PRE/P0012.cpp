/*
어떤 개미집은 N개의 방들로 구성되어 있고 방들은 이진트리의 형태로 연결되어 있다. 방들은 1번부터 N번까지 번호가 붙어 있다.
개미는 N마리가 있는데 개미들도 1번부터 N번까지 번호가 붙어 있다. 어느날 개미들은 각자 서로 다른 방에서 출발해서 자신의 번호가 붙어 있는 방으로 이동하였다. 개미들은 자신이 출발한 방에서 자신의 목적지 방까지 최단 경로를 통해 이동하였다.
모든 이동이 끝난 후 개미들에게 어떤 길을 통해서 자신의 목적지에 도달했는지 물어보았다. 개미들은 기억력이 좋지 못해서 자신의 출발지와 지나온 방들을 제대로 기억하지 못하고, 단지 몇 개의 방 번호만을 말했다. 말한 방 번호도 정확한 것이 아니었다. 자신이 지나지 않은 방의 번호를 말을 하는 경우도 많았다. 단, 다음의 규칙은 만족이 되는 것을 확인하였다.

규칙1. 한 개미가 말한 방 번호들 중 개미집의 루트와 목적지 방을 연결하는 최단 경로 상에 있는 방들 중 루트에 가장 가까운 방은 반드시 지난 방이다.
규칙2. [규칙1]에서 말한 그 방이 최단 경로에 있는 방들 중 실제로 루트에 가장 가까운 방이었다. 
(위에서 말하는 최단 경로 상에 있다는 것은 루트와 목적지도 포함하는 것이다. 또한, 루트에 가장 가깝다는 것은 거리가 0인 경우도 포함한다. 즉, 루트 자체가 그러한 방일 수도 있다.)

아래 그림을 보자. 아래 그림에서 루트는 5번 방이다. 6번 방에 도착한 개미가 4, 7, 8, 번의 방을 말했다고 하면 그 중 4번 방이 개미집의 루트인 5번과 목적지인 6번 방을 잇는 경로 사이에 있으므로, 개미가 말한 방들 중 4번 방이 개미가 이동한 경로 상에 있는 방이며, 이동경로 중 루트에 가장 가까운 방이라는 것을 알 수 있다. 즉, 이 개미는 2번이나 4번 방에서 출발한 것이다.
여왕개미는 모든 개미들에게서 위와 같은 정보를 얻었다. 놀랍게도 여왕개미는 이 정보들만 가지고 모든 개미가 이동한 거리의 합을 계산할 수 있었다. 위와 같은 정보를 받아서 모든 개미가 이동한 거리의 합을 계산하는 프로그램을 작성하시오. 주어진 입력값만으로 다양한 경우의 최초위치와 그에 따른 여러종류의 거리의 합을 유추할 수 있다면, 그 중 임의의 경우에 대한 이동거리의 합을 출력하여도 답으로 인정된다.
예) 만약 모든 이동이 끝난 후 개미들의 위치와 각 개미가 부른 방번호가 아래와 같다면
1번개미는 5번방에서, 2번개미는 1번방에서, 3번개미는 2번방에서, 4번개미는 3번방에서, 5번개미는 4번방에서 이동해 왔음을 유추할 수 있다.
따라서 최초위치가 위와 같은 경우 총 이동경로의 합은 2 + 1 + 2 + 2 + 3 = 10 이 된다.

[입력] 
입력 파일의 제일 첫째 줄에는 파일에 포함된 케이스의 수 T가 주어진다. 각 케이스의 첫째 줄에 개미 집의 방 개수 N이 주어진다. (2 ≤ N ≤ 40,000) 다음 N개의 줄 중 X번째 줄에는 X번 방에 대해서 그 방이 연결된 방식과 도착한 개미가 말한 방 번호들이 주어진다. 각 줄의 첫 수는 X의 부모 방의 번호이다. 두번째 수가 0인 경우 X는 부모의 왼쪽 자식이며, 1인 경우 X는 부모의 오른쪽 자식이다. 첫 수가 0인 경우는 X가 루트라는 뜻이며, 이때 두번째 수는 읽어들이고 무시하여야 한다. 세번째 수는 개미가 말한 방의 개수이다. 각 개미는 최소 1개, 최대 10개의 방 번호를 말하였다. 같은 줄에 이어서 개미가 말한 방의 번호들이 주어진다. 답을 계산하는 것이 불가능한 경우는 주어지지 않는다.

[출력] 
각 테스트 케이스의 답을 순서대로 표준출력으로 출력하며, 각 케이스마다 줄의 시작에 “#x”를 출력하여야 한다. 이때 x는 케이스의 번호이다. 같은 줄에, 개미들이 이동한 거리의 총 합을 출력한다.

[입출력 예]
(입력)

3                                              ← 3 test cases in total
8                                              ← 1st case
5 0 4 8 5 3 7
4 0 2 1 4
8 1 4 1 4 7 8
1 0 4 7 3 4 6
0 0 3 3 5 8
4 1 2 7 4
8 0 2 5 8
5 1 1 5
5                                             ← 2nd case
3 0 3 3 5 2 
1 1 2 4 1
0 1 4 1 2 3 4
1 0 1 3
3 1 4 1 3 4 5
3                                             ← 3rd case
0 0 1 1
1 0 1 1
1 1 1 1

(출력)
#1 16
#2 10
#3 4 
*/

/*
import java.io.*;
import java.util.*;

public class Solution {

	static final int max=40000;
	static final int high = (int)(Math.log(max)/Math.log(2));
	static int N, ans, root;
	static int[] depth, npath;
	static int[][] par, path;
	static ArrayList<Integer>[] adj = new ArrayList[max+1];
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		for(int ts=1;ts<=T;ts++){
			N = Integer.parseInt(br.readLine());

			depth = new int[N+1];
			npath = new int[N+1];
			par   = new int[N+1][high+1];
			path  = new int[N+1][11];
			for(int i=0;i<=N;i++){
				adj[i] = new ArrayList<Integer>();
			}

			for(int i=1;i<=N;i++){
				StringTokenizer st = new StringTokenizer(br.readLine());
				int p   = Integer.parseInt(st.nextToken());
				
				if(p==0) root = i;
				adj[p].add(i);
				par[i][0] = p;
				
				st.nextToken();

				npath[i] = Integer.parseInt(st.nextToken());

				for(int j=1;j<=npath[i];j++){
					path[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			setDepth(root);
			
			setParent();
			
			getAnswer();		
			
			bw.write("#"+ts+" "+ans);
			bw.newLine();
			bw.flush();
		}
		bw.close();
	}
	static void getAnswer(){
		ans = 0;
		int[] v = new int[N+1];
		for(int i=1;i<=N;i++){
			int md = Integer.MAX_VALUE;
			int tmp = 0;
			for(int j=1;j<=npath[i];j++){
				int p = path[i][j];

				if(isParent(i, p)){

					if(md > depth[p]){

						md = depth[p];
						v[i] = 2*(depth[i] - md);
					}
				}
			}
			ans += 2*(depth[i] - md);;
		}
	}
	static boolean isParent(int x, int y){
		if(depth[y] > depth[x]){
			int tmp = x;
			x = y;
			y = tmp;
		}
		int ix  = 0;
		int gap = depth[x] - depth[y];
		while(gap != 0){
			if(gap%2==1) x = par[x][ix];
			ix++;
			gap /= 2;
		}
		if(x==y) return true;
		else return false;
	}
	static void setDepth(int r){
	    Queue<Integer> que = new LinkedList<>();
	    que.add(r);
	    while(!que.isEmpty()){
	    	int x = que.poll();
	    	for(int t : adj[x]){
	    		depth[t] = depth[x] +1;
	    		que.add(t);
	    	}
	    }
	}
	static void setParent(){
		for(int j=1;j<=high;j++){
			for(int i=1;i<=N;i++){
				par[i][j] = par[par[i][j-1]][j-1];
			}
		}
	}
}
*/

