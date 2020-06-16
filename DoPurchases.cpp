#include "StdAfx.h"
#include "DoPurchases.h"
namespace DoPurchases
{
    vector<Purchases> vPurchases;
    void init()
    {
        Purchases tu;
        ofstream f1("Purchases.txt", ios::out | ios::app);
        f1.close();
        ifstream fin("Purchases.txt");
        if (!fin)
        {
            cerr << "文件打开失败" << endl;
            exit(1);
        }
        while (fin.peek() != EOF)
        {
            fin >> tu.id >> tu.ISBN >> tu.priority >> tu.quantity >> tu.detail;
            vPurchases.push_back(tu);
        }
        fin.close();
    }
    void saveAll()
    {
        ofstream fout("Purchases.txt");
        if (!fout)
        {
            cerr << "文件打开失败" << endl;
            exit(1);
        }
        for (vector<Purchases>::iterator iterPurchases = vPurchases.begin(); iterPurchases != vPurchases.end(); iterPurchases++)
        {
            fout << iterPurchases->id << ' ' << iterPurchases->ISBN << ' ' << iterPurchases->priority << ' ' << iterPurchases->quantity << ' ' << iterPurchases->detail;
            if (iterPurchases + 1 != vPurchases.end())
            {
                fout << endl;
            }
        }
        fout.close();
    }
    void displayAllPurchases()
    {
        for (vector<Purchases>::iterator iterPurchases = vPurchases.begin(); iterPurchases != vPurchases.end(); iterPurchases++)
        {
            cout << "ID：" << iterPurchases->id << "\t书名：" << DoBook::ISBNToName(iterPurchases->ISBN) << "\t优先级：" << iterPurchases->priority << "\t数量：" << iterPurchases->quantity << endl;
        }
    }
    void modifyOnePurchases()
    {
        unsigned int tid;
        cout << "请输入希望修改的采购单ID：";
        cin >> tid;
        for (vector<Purchases>::iterator iterPurchases = vPurchases.begin(); iterPurchases != vPurchases.end(); iterPurchases++)
        {
            if (iterPurchases->id == tid)
            {
                unsigned int tQuantity;
                cout << "请输入新的采购数量：";
                cin >> tQuantity;
                iterPurchases->quantity = tQuantity;
                saveAll();
                cout << "采购数量修改成功\n";
                return;
            }
        }
        cerr << "找不到指定ID\n";
        return;
    }
    void newPurchases()
    {
        Purchases tu;
        vector<Purchases>::iterator iterPurchases = vPurchases.end();
        iterPurchases = iterPurchases - 1;
        tu.id = (iterPurchases->id) + 1;
        cout << "请输入希望采购的图书的ISBN：";
        cin >> tu.ISBN;
        cout << "请输入希望采购的图书的数量：";
        cin >> tu.quantity;
        cout << "请输入采购单补充信息：";
        cin >> tu.detail;
        tu.priority = 0;
        vPurchases.push_back(tu);
        saveAll();
        cout << "采购单新增成功\n";
        return;
    }
} // namespace DoPurchases