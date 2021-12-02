#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void draw_point(Mat& img, Point2d p, Scalar color){
    circle(img, p, 5, color, -1);
}

void draw_delaunay(Mat &img, Subdiv2D &subdiv){
    vector<Vec4f> edges;
    subdiv.getEdgeList(edges);

    for(auto &edge:edges){
        line(img, Point2f(edge[0], edge[1]), Point2f(edge[2], edge[3]), Scalar(0, 255, 0));
    }
}

void draw_voronoi(Mat &img, Subdiv2D &subdiv){
    vector<vector<Point2f> > facetList;
    vector<Point2f> facetCenters;
    subdiv.getVoronoiFacetList(vector<int>(), facetList, facetCenters);

    for(auto &trig : facetList){
        vector<Point2f>::iterator it = trig.begin();
        Point2f p1 = *it;
        it++;
        while(it != trig.end()){
            Point2f p2 = *it;
            line(img, p1, p2, Scalar(255, 255, 255));
            p1 = p2;
            it++;
        }
    }
}

int main() {
    string filename = "kani.jpeg";

    cout << CV_VERSION << endl;
    // 対象画像をグレイスケールで読み込み
    Mat img = imread(filename, IMREAD_GRAYSCALE);


    // Shi-Tomasi Corner Detector
    int maxCorners = 0;
    vector<Point2f> corners;
    goodFeaturesToTrack(img, corners, maxCorners, 0.01, 50);

    // 出力用ファイルを作成
    Mat out = imread(filename);
    for(auto &point : corners){
        draw_point(out, point, Scalar(0,0,255));
    }

    // Delaunay分割のためのSubdiv2Dを初期化
    Size size = out.size();
    Rect rect(0, 0, size.width, size.height);
    Subdiv2D subdiv(rect);

    // 点を追加する
    subdiv.insert(corners);

    draw_voronoi(out, subdiv);
    draw_delaunay(out, subdiv);

    namedWindow("Delaunay");
    imshow("Delaunay", out);

    waitKey();

    return 0;
}