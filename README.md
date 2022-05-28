# Point-Cloud
## 功能:
讀取pcd、txt檔案並顯示在QVTKWidget上、
使用QSlider更改點雲顏色與大小、
開啟txt檔....

## 2022/05/28 新增
攝像頭擷取圖像，並利用opcv將圖像轉為灰階模擬深度圖像，接著產生point cloude文件並儲存。

 ## 使用方法:
   此段為相機參數需要因應使用之攝像頭調整
   
     ```
      //相機內參
      const double camera_factor = 1000;
      const double camera_cx = 325;
      const double camera_cy = 253;
      const double camera_fx = 518;
      const double camera_fy = 519;
     ```
   -------------
   此段為利用opencv使用攝像頭
   
      ```
      PointCloudT::Ptr cameracloud(new PointCloudT);
	VideoCapture cap(0);
	Mat frame;
	Mat rgb, depth;
	consoleLog("Open Camera", "", "", "push q to save the pcd file");
	while (true) {
		// 擷取影像
		bool ret = cap.read(frame);
		if (!ret) {
			cout << "Can't receive frame (stream end?). Exiting ...\n";
			break;
		}
		// 顯示圖片
		imshow("live", frame);

		
      ```
   -------------------
   此段為利用2D圖片轉為point cloud 之pcd文件
   
     ```
    	// 按下 q 鍵離開迴圈並回傳mypicture
		  if (waitKey(1) == 'q') {
			mypicture = frame;
			rgb = mypicture;
			depth = mypicture;
			cvtColor(rgb, depth, COLOR_BGR2GRAY);
			imshow("rgb", rgb);
			imshow("depth", depth);
			for (int m = 0; m < rgb.rows; m++) {
				for (int n = 0; n < rgb.cols; n++)
				{
					ushort d = depth.ptr<ushort>(m)[n];
					if (d == 0)
						continue;
					PointT p;

					//空間座標
					p.z = double(d) / camera_factor;
					p.x = (n - camera_cx) * p.z / camera_fx;
					p.y = (m - camera_cy) * p.z / camera_fy;
					//由RGB圖取得色彩
					p.b = rgb.ptr<uchar>(m)[n * 3];
					p.g = rgb.ptr<uchar>(m)[n * 3 + 1];
					p.r = rgb.ptr<uchar>(m)[n * 3 + 2];
					//把p加入點雲
					cameracloud->points.push_back(p);
					//testcloud.cloud->points.push_back(p);
				}
			}
			//儲存點雲
			cameracloud->height = 1;
			cameracloud->width = cameracloud->points.size();
			//testcloud.cloud->height = 1;
			//testcloud.cloud->width = testcloud.cloud->points.size();
			//cout << "point cloud size = " << testcloud.cloud->points.size() << endl;
			cameracloud->is_dense = false;
			pcl::io::savePCDFile("E:/test.pcd", *cameracloud);
			break;
		}
	}
     ```
    
## 目前缺點
   * 只有普通攝像頭沒辦法拍攝深度圖 
   * 攝像頭的內參(像素質、聚焦、光學中心)不知道如何取得
   * 目前顯示會有色彩消失問題
    
   ![](https://github.com/tim60936/QtWidgetsApplication1/blob/master/%E5%9C%96%E7%89%871.png)
  
  
