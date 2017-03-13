﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"scdtree.h"
#include"QFileDialog"
#include"QTreeWidget"
#include"datastruct.h"
#include<QTreeView>
#include <QModelIndex>
#include <QStandardItemModel> 
#include"userdefinedelegate.h"
#include"importoneied.h"
#include "adddatesetdlg.h"
#include"inputdialog.h"
#include"comm_check.h"
#include "MessageHandler.h"
#include "droptable.h"
#include <QMap> 
//#include <QXmlSchemaValidator> 
//#include <QAbstractMessageHandler> 
#include <QUrl> 
//#include <QXmlSchema> 
#include <QDir> 
#include "SchemaCheck.h"
#include "legitimacyverification.h"
#include "terminaltypecheck.h"
#include "logicmap.h"
#include"iecconfig.h"
#include"batchimportcid.h"
#include"reload.h"
#include "mmsextra.h"
#include"exportcid.h"
#include"datadescchange.h"
#include"importxls.h"
#include<QFileInfo>
#include"mergescd.h"
#include "Wait_Dlg.h"
/*#include<xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/util/OutOfMemoryException.hpp> */
//#include "SAX2PrintHandlers.hpp"  
using namespace  std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    ScdTree *m_SCDPoint;
    int File_state;
    QString SCD_FilePath;
    QMenu *m_IEDMenu;
    QMenu *m_DataMenu;
	QMenu *m_DataSetMenu;
    QMenu *m_GSEMenu;
    QMenu *m_SMVMenu;
    QMenu *m_InputMenu;
    QMenu *m_SubMenu;
    QMenu *m_CommMenu;
    QMenu *m_HeaderMenu;
	QAction *actionAdd;
	QAction *actionDel;
    QAction *actionMovUp;
    QAction *actionMovDown;
	QAction *actionExtra;
	QAction *actionIncrease;
	QAction *actionBatch;
    QAction *actionImportOneIed;
    QAction *actionBatchImportIED;
	QAction *actionDelOneIed;
    QAction *actionReLoad;
    QAction *actionExportIed;
    QAction *actionFindIed;
    QAction *actionConfig;
    QAction *actionRename;
    QTreeWidgetItem *T_parent;
    QVector<HistoryItem> HistoryItemList;
    QVector<CommItem> CommItemList;
    QStandardItemModel *m_ModelHeader;
    QStandardItemModel *m_ModelTree;
    QStandardItemModel *m_ModelSubstation;
    QStandardItemModel *m_ModelCommunication;
    QStandardItemModel *m_ModelSubNet;
    QStandardItemModel *m_ModelIED;
    QStandardItemModel *m_ModelIEDNode;
    QStandardItemModel *m_ModelIED_LD;
    QStandardItemModel *m_ModelIED_LN;
    QStandardItemModel *m_ModelIED_DataSetData;
    QStandardItemModel *m_ModelIED_GSE;
    QStandardItemModel *m_ModelIED_Input;
    QStandardItemModel *m_ModelIED_SMV;
    QStandardItemModel *m_ModelIED_Log;
    QStandardItemModel *m_ModelIED_Report;
    QStandardItemModel *m_ModelIED_DataSet;
    QStandardItemModel *m_ModelIED_MmsNet;
    QStandardItemModel *m_ModelIED_GooseNet;
    QStandardItemModel *m_ModelIED_SmvNet;
    QItemSelectionModel *m_ModelSlection;

    QStringList headerList;
    QTreeWidgetItem * CurrentItem;
	int CurrentNodeType;
	int ChildNodeType;
    QString strIEDname;
    QString CurrentTitle;
    QVector<IEDstruct> IedList;
	QVector<FCDA_Struct> DataSetDataList;
	QMap<quint16, FCDA_Struct>FCDA_MAP;
	QVector<DataSetStruct>DataSet_Vector;
    QVector<Data_instStruct> Data_instList;
	QVector<Data_instStruct> DatainstList;
	//QVector<DataMatrix_Struct> DataMatrix_Vector_Select;
	QVector<DataMatrix_Struct> DataMatrix_Vector_LD;
	QVector<FCDA_Struct> DataInstList_LD;
	QVector<FCDA_Struct> DataInstList_Select;
	QMap<QString, ConnectedAP>ConnectAP_MAP;
    QStandardItemModel *model_Tree;
    QString currentDataset;
    QString currentLD;
    bool GSE_Enable_flag;
    QStringList datasetlist;
    QString strGsename;
	QString strSMVname;
    QString strRPTname;
    QString strLOGname;
    int Change_Flag;
	QStringList LnodeTyepList;
	int GOOSE_Flag;
    HistoryItem CurrentHistoryItem;
    int Version_Flag;
    int Reversion_Flag;
	int Language_Type;
	//QVector<Data_instStruct> lninstList;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Init_Display();
    void DisplayNode(ScdTree*);
    void InitSCDtree();
    void Init();
    void Init_Tree();
	void Init_Menu();
    void Init_Frame();
    void SCLTree_IED_RightClick(const QPoint &pos);
    void SCLTree_SubStation_RightClick(const QPoint &pos);
    void SCLTree_Header_DoubleClick(QString str);
    void SCLTree_SubStation_DoubleClick(QString str);
    void SCLTree_Communication_DoubleClick(QString str);
    void SCLTree_IED_DoubleClick(QString str);
    void SCLTree_IEDNODE_DoubleClick(QString str);
    void SCLTree_SubNet_DoubleClick(QString str);
    void Init_Header();
    void Init_Substation();
    void Init_Communication();
    void Init_SubNet();
    void Init_IED();
    void Init_IEDNODE();
    void Init_MMSNET();
    void Init_GOOSENET();
    void Init_SMVNET();
    void Element_Hide(QString str);
    void DisplayHeader(QString str);
    void DisplayCommunication(QString str);
	void DisplayIEDnode(QString str);
    void Get_CommunicationList(QString str);
    void Get_IEDList(QString str);
    void Get_History(QString str);
    void Get_Communication(QString str);
    void AddOneHistoryToTable(int row, HistoryItem Item);
    void AddOneSubnetToTable(int row, CommItem Item);
	void AddOneIEDToTable(int row, IEDstruct Item);
    void AddOneHistory();
    void AddOneSubNet();
    void AddOneDatSet();
    void RenameOneDatSet(QString name,QString desc);
    void AddOneGSECTRL();
    void AddOneSMVCTRL();
    void DelOneSubNet(QModelIndex index,QString strname);
	void DelOneGSECTRL();
    void DelDataSetData();
    void DelDataSet();
    void Get_Node(QString str);
    int  Import_OneIED(int state);
	void AddoneItemToTree(QString str1, QString str2);
    void Init_GSE();
    void Init_Input();
    void Init_Log();
    void Init_LogicDevice();
    void Init_LogiceNode();
    void Init_DataSet();
    void Init_DataSetData(int state);
    void Init_Report();
	void Init_Combox_LD();
    void Init_Combox_LN(QString strLD);
    void Init_SMV();
	void DisplayLD();
    void DisplayLN(QString str);
    void DisplayDataSet();
	void DisableFun();
	void EnableFun();
	int  GetCurrentLD();
    int  GetSpecifytLD(QByteArray strLDname);
	int  GetSpecifytLN(QString strapname, QString strLNname, QString&, QVector<LN_InstStruct>&);
	int  GetCurrentLN();
	//void Get_AccessPoint();
	void AddLDToTable(QString strAp);
    void AddLDToCombox(QString strAp);
    void AddLNToCombox(QString strAp);
	void AddOneLDToTable(int row);
    void AddOneLNToTable(int row);
    void AddOneGSEToTable(int row);
    void AddOneDataSetToTable(int row);
    void AddOneRPTToTable(int row,RPT_CTRLStruct &data);
    void AddOneLOGToTable(int row,LOG_CTRLStruct &data);
    void AddOneInputToTable(int row,Input_Struct &data);
	void GetOneLogicDevice();
	void DisplayDataSetDate(QString strname);
    void GetDataSetData();
    void GetDataSetData_inst();
	void GetDataSetData_inst(int state);
	void AddOneDataToTable(int row, Data_instStruct m_data,int state);
	void AddOneDataToTable(int row, FCDA_Struct m_data, int state);
    void AddOneApToCombox(QString strAp);
    void Init_Combox_FC();
    void Init_LineEdit_DA();
    int  Check_FC(QString lbtype,QString doName);
    void ADDDatainstListTOTree(LN_InstStruct &LNlist, QVector<Data_instStruct> &Datalist);
	void ADDDatainstListTOTree(QVector<FCDA_Struct>&List);
	void analyzeLN(DataLN_Struct m_DataLN);
	int  AddOneDataToDataSet(FCDA_Struct data);
    void OnGSECtrlClicked(const QModelIndex & index);
	void OnMMSClicked(const QModelIndex & index);
    void DisplayGSE();
    void DisplaySMV();
    void DisplayRPT();
    void DisplayLOG();
    void DisplayInput();
    void GetRPTFromSCD(RPT_CTRLStruct* data);
	void GetRPTFromTable(int row,RPT_CTRLStruct* data);
    void GetLOGFromSCD(LOG_CTRLStruct* data);
    void GetLOGFromTable(int row,LOG_CTRLStruct &data);
    bool GetInputFromSCD(Input_Struct* data);
	
    void GetInputFromTable(int row,Input_Struct* data);
    void AddOneSMVToTable(int row);
    void DelOneSMVCTRL();
    void OnSMVCtrlClicked(const QModelIndex & index);
    void OnRPTCtrlClicked(const QModelIndex & index);
    void OnLOGCtrlClicked(const QModelIndex & index);
    void OnRPTCtrldoubleClicked(const QModelIndex & index);
    void OnLOGCtrldoubleClicked(const QModelIndex & index);
    //void OnSMVCtrlClicked(const QModelIndex & index);
	void ClearTableDelegate(int size);
//    void DisplaySubNet();
    void DisplayMMSNet(QString str);
	void AddMMSNetToTable(QVector<ConnectedAP>&);
    void DisplayGOOSENet(QString str);
	void AddGOOSNetEToTable(QVector<ConnectedAP>&);
    void DisplaySMVNet(QString str);
	void AddSMVNetToTable(QVector<ConnectedAP>&);
	int File_Integrity_Check(int state);
	int File_Integrity_Check(QString);
    int Schema_Check();
	int Filter_datainst(FCDA_Struct &);
	void CreatFCDAList(QVector<DataMatrix_Struct>, QVector<FCDA_Struct>, QVector<FCDA_Struct>&);
private slots:
    void Action_New();
	void Action_Load();
    void Header_DoublClick(QModelIndex);
    void Action_Save_As();
	void Action_Save();
    void Action_Add();
    void Action_Del();
	void Action_Extra();
    void Action_Rename();
    void Action_Config();
    void SCLTree_MousEvent(const QPoint &pos);
	void TableView_MousEvent(const QPoint &pos);
    void SubstationTree_MousEvent(const QPoint &pos);
    void IEDTree_MousEvent( const QPoint &pos);
    void openMenuProgram(QTreeWidgetItem*, int);
    void ImportOneICD();
	void ImportOneCID();
    void OnHeaderDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void OnCommDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
	void OnSubnetDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void OnIEDDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
	void OnLDDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
	void OnLNDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void OnDataDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void OnGSEDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void OnSMVDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void OnRptDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void OnLogDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void OnMmsNetDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void OnGooseNetDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void OnSmvNetDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);

    void OnDataSetdoubleClicked(const QModelIndex & index);
    void OnDataSetDataClicked(const QModelIndex & index);
    void OnTableViewClicked(const QModelIndex & index);
	void OnHorizontalHeaderClicked(const QModelIndex & index);
    void OnTableViewdoubleClicked(const QModelIndex & index);
    void PushButton_DataSet_Click();
    void PushButton_GSE_Click();
    void PushButton_Input_Click();
    void PushButton_Log_Click();
    void PushButton_LogicDevice_Click();
    void PushButton_LogiceNode_Click();
    void PushButton_Report_Click();
    void PushButton_SMV_Click();
    void Combox_LD_Active(QString str);
    void Combox_LN_Active(QString str);
    void PushButton_Fresh();
    void IEDTreeDoubleClicked(QTreeWidgetItem * item, int column);
	void Action_Integrity_Check();
	void Action_Communication_Check();
	void Action_Schema_Check();
	void Action_Model_validation_check();
	void Action_Type_Terminal_check();
    void Action_IECConfig();
    void Action_LogicMap();
    void Action_BatchImport();
    void Action_Reload();
	void Action_DelIED();
	void Action_ExportCID();
	void Action_ExportXLS();
	void Action_ExportXML();

	void Action_Increase();
	void Action_Batch();
    void DataSetDate_MousEvent( const QPoint &pos);
	void Auto_SetMmsNet();
	void Auto_SetGooseNet();
	void Auto_SetSmvNet();
	void Auto_Init_Communication();
	void Action_ClearInput();
    void ReceiveChange(int state);
    void TableView_Row_Select(QModelIndex row);
    void Auto_AddControlBlock();
    void Action_ImportMap();
    void Action_MergeSCD();
    void Action_SwitchLanguage();
    void Action_Close();
    void Action_CID_Contain();
    void Action_currentChanged(int);
    void Tree_itemClicked(QTreeWidgetItem *item, int column);
    //void Action_Del_ALLInput();
private:
    void AddNewHistoryItem();
    void GetGSEBLKFromTable(int row ,GSE_InstStruct &data);
    void GetSMVBLKFromTable(int row ,SMV_InstStruct &data);
    void AddOneSMVToTable(int row,SMV_InstStruct &data);
    void AddOneGSEToTable(int row,GSE_InstStruct &data);
    int RPT_STATE;
	int GSE_STATE;
    bool DataSet_Change;
signals:
    void SendChange(int state);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
