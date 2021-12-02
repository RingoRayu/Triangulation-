#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

/*
参考 : 
https://recruit.cct-inc.co.jp/tecblog/com-geometry/delaunay/
Python, OpenCV : 
https://note.nkmk.me/python-opencv-delaunay-voronoi/
https://tech-blog.s-yoshiki.com/entry/69
*/

/*
1. 三角形分割 T を「P を覆う十分に大きな三角形」で初期化する。
2. 点 pr∈P をランダムに選択する。
3. pr を含む三角形 ∈ T を探す。
4. 三角形 △ を pr を含む小さな三角形に分割する。
5. 「違反辺」がなくなるまで辺フリップを行う。
6. P のすべての点が T に追加されるまでステップ 2-5 を繰り返す。
7. P の凸包上の辺であって T に張られていないものがあれば追加する。
8. ステップ 1 で生成した三角形とそれに付随する辺を削除する。
*/


class point{
    public:
        ld x, y;
};

class edge{
    public:
        point e1, e2;
};

class triangle{
    public:
        point e1, e2, e3;
};

//点の集合を包含する三角形を導く
triangle implication_triangle(vector<point> p){
    //凸法で一番外側の点の集合を導き出す

}

int main()
{
    //点の座標の集合
    vector<point> p;
    //点の数
    int n;
    //入力
    cin >> n;
    rep(i, n){
        ld x, y;
        cin >> x >> y;
        point tmp;
        tmp.x = x;
        tmp.y = y;
        p.push_back(tmp);
    }

    // 1. 三角形分割 T を「P を覆う十分に大きな三角形」で初期化する。





    return 0;
}