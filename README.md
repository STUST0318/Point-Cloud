# Point-Cloud
## 功能:
讀取pcd、txt檔案並顯示在QVTKWidget上、
使用QSlider更改點雲顏色與大小、
開啟txt檔

## 2022/05/04 新增
標記點，並取得點的三維座標

## 2022/05/11 新增
區域選取、顯示座標系、色彩選取方塊

## 2022/05/20 新增
狀態列顯示

 ## 使用方法:
   *consoleLog(QString, QString, QString, QString);
   ```
	void QtWidgetsApplication1::consoleLog(QString operation, QString subname, QString filename, QString note) {
	int rows = ui.consoleTable->rowCount();
	ui.consoleTable->setRowCount(++rows);
	QDateTime time = QDateTime::currentDateTime();//獲取系統時間
	QString time_str = time.toString("MM-dd hh:mm:ss"); //時間顯示格式
	ui.consoleTable->setItem(rows - 1, 0, new QTableWidgetItem(time_str));
	ui.consoleTable->setItem(rows - 1, 1, new QTableWidgetItem(operation));
	ui.consoleTable->setItem(rows - 1, 2, new QTableWidgetItem(subname));
	ui.consoleTable->setItem(rows - 1, 3, new QTableWidgetItem(filename));
	ui.consoleTable->setItem(rows - 1, 4, new QTableWidgetItem(note));

	ui.consoleTable->scrollToBottom(); //滾動至底部
}
   ```
   
   ![](https://github.com/tim60936/QtWidgetsApplication1/blob/master/%E5%9C%96%E7%89%871.png)
  
  
