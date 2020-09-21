#include <iostream>
#include <vector>

using namespace std;

const int PATH_COLOR = 0;
const int WALL_COLOR = 1;
const int START_COLOR = 2;
const int END_COLOR = 3;
const int VISITED_COLOR = 4;
const int NOTPATH_COLOR = 5;

vector<vector<int>> arr;
vector<int> visited;
int answer;

bool findFinalPath(int r , int c){
	if(r < 0 || c < 0 || r >= 16 || c >= 16){
    	return false;
    }
    else if(arr[r][c] == END_COLOR){
        answer = 1;
    	return true;
    }
    else if(arr[r][c] != PATH_COLOR)
        return false;
    else{
        arr[r][c] = VISITED_COLOR;
        if(findFinalPath(r-1,c) ||findFinalPath(r,c+1) || findFinalPath(r+1,c) || findFinalPath(r,c-1))
            return true;
        arr[r][c] = NOTPATH_COLOR;
        return false;
    }
}
    
int main(int argc, char** argv)
{
	int test_case;
	int T,N;
	char temp;
    T = 10;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
        answer = 0;
        for(int i = 0 ; i  < 16 ; i++){
            arr.push_back(vector<int>());
        	for(int j = 0 ; j < 16; j++){
            	cin >> temp;
                arr[i].push_back((int)temp-48);
            }
        }
        arr[1][1] = 0;
        findFinalPath(1,1);

        cout << "#" << test_case << " " << answer << endl;
        arr.clear();
	}
    
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}