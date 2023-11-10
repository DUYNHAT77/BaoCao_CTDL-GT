#include<bits/stdc++.h>
using namespace std;

//===Quan Ly Nguoi Dong Thue(Danh sach lien ket don)===

struct NGUOIDONGTHUE
{
	int maNguoiDT;
	int maThue;
	char tenCongTy[100];
	char diaChi[100];
	float dienTich;
	char quyMo[20];
	char nguoiDungDau[50];
	float donGia;
	float tienThue;
	
};

//ds lk don

struct Node
{
	NGUOIDONGTHUE info;
	struct Node*next;
};

struct List
{
	Node *Head;
	Node *Tail;
};
//khoi tao ds rong
void KhoiTao(List &Q)
{
	// Khởi tạo đầu và đuôi của Q thành NULL
	Q.Tail=NULL;
	Q.Head=NULL;
}

//tao nut chua thong tin can bo
// Hàm getNode tạo một Node mới và khởi tạo nó với thông tin đã cho.
Node *getNode(NGUOIDONGTHUE x)
{
// tạo một con trỏ Node mới
    Node *pNDT;
    pNDT=new Node;
    
// kiểm tra xem cấp phát bộ nhớ có thành công không
    if(pNDT==NULL)
    {
        cout<<"cap phat loi"<<endl; // nếu không, hiển thị thông báo lỗi
        return 0; // trả về con trỏ null
    }
    
    // đặt thông tin của Nút mới cho đầu vào đã cho
    pNDT->info=x;
    
  // khởi tạo con trỏ tiếp theo của Nút mới thành null
    pNDT->next=NULL;
    
 // trả về con trỏ Node mới
    return pNDT;
}
void insertLast(List &Q, Node *pNDT)
{
	// Kiểm tra xem danh sách có trống không
	if(Q.Head==NULL)
	{
	// Chèn nút làm nút đầu tiên
		Q.Head=pNDT;
		Q.Tail=Q.Head;
	}
	else 
	{
	// Chèn nút vào cuối danh sách
		Q.Tail->next=pNDT;
		Q.Tail=pNDT;
	}
}
void nhapNDT(NGUOIDONGTHUE &x)
{
	cout<<"Nhap ma nguoi dong thue:"; cin>>x.maNguoiDT;
	cout<<"Nhap ma thue: "; cin>>x.maThue;
	fflush(stdin);
	cout<<"Nhap ten cong ty: "; gets(x.tenCongTy);
	cout<<"Nhap dia chi: "; gets(x.diaChi);
	cout<<"Nhap quy mo: "; gets(x.quyMo);
	cout<<"Nhap nguoi dung dau: "; gets(x.nguoiDungDau);
	cout<<"Nhap dien tich: "; cin>>x.dienTich;
	if(x.dienTich<3000){
		x.donGia=5000;
		x.tienThue=5000*x.dienTich;
	}else if(x.dienTich>=3000 and x.dienTich<=5000){
		x.donGia=4000;
		x.tienThue=4000*x.dienTich;
	}else if (x.dienTich>5000){
		x.donGia=3000;
		x.tienThue=3000*x.dienTich;
	}
	
}
void NhapDSNDT(List &Q)
{
    int n; // so nguoi dong thue
    Node *pNDT; // node trong danh sach
    NGUOIDONGTHUE x; // thong tin nguoi dong thue
    cout << "Nhap so nguoi dong thue: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        nhapNDT(x); // nhap thong tin nguoi dong thue
        pNDT = getNode(x); // tao node moi voi thong tin
        insertLast(Q, pNDT); // them node moi vao danh sach
    }
}

void xuatNDT(NGUOIDONGTHUE x)
{
	cout<<setw(18)<<left<<x.maNguoiDT<<"\t";
	cout<<setw(8)<<left<<x.maThue<<"\t";
	cout<<setw(12)<<left<<x.tenCongTy<<"\t";
	cout<<setw(7)<<left<<x.quyMo<<"\t";
	cout<<setw(10)<<left<<x.diaChi<<"\t";
	cout<<setw(18)<<left<<x.nguoiDungDau<<"\t";
	cout<<setw(8)<<left<<x.dienTich <<"\t";
//	cout<<endl;
	cout<<setw(7)<<left<<x.donGia <<"\t\t";
	cout<<setw(10)<<left<<x.tienThue;
	cout<<endl;
	
}
void xuatDSNDT(List &Q)
{
	Node*pNDT;
	cout<<"===== Danh sach hien co:"<<endl;
	cout<<setw(18)<<left<<"Ma Nguoi Dong Thue"<<"\t"
	<<setw(8)<<left<<"Ma Thue"<<"\t"
	<<setw(12)<<left<<"Ten Cong Ty"<<"\t"
	<<setw(7)<<left<<"Quy Mo"<<"\t\t"
	<<setw(10)<<left<<"Dia Chi"<<"\t"
	<<setw(18)<<left<<"Nguoi Dung Dau"<<"\t"
	<<setw(8)<<left<<"Dien Tich"<<"\t";
//	cout<<endl;
	cout<<setw(7)<<left<<"Don Gia"<<"\t\t" <<setw(10)<<left<<"Thanh Tien"<<endl;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	   xuatNDT(pNDT->info);
}


//tim lkien
// hàm tìm kiếm một người trong hàng đợi
Node *search(List &Q, int k)
{
// khởi tạo một con trỏ tới đầu hàng đợi
	Node *pNDT;

// lặp qua hàng đợi để tìm người có id 'k'
	for (pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	    if (pNDT->info.maNguoiDT==k) break;

// trả con trỏ về nút người
	return pNDT;
}
void sapxeptheodientich(List &Q)
{
	Node *pNDT, *q;
	NGUOIDONGTHUE tg;

// Sắp xếp danh sách bằng thuật toán sắp xếp lựa chọn
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	   for (q=pNDT->next;q!=NULL;q=q->next)
	     if (pNDT->info.dienTich > q->info.dienTich)
	       {

// Hoán đổi các nút nếu dienTich của chúng không đúng thứ tự
	       	tg=pNDT->info;
	      	pNDT->info=q->info;
	      	q->info=tg;
		   }   
}

void ThongKe(List &Q, char quyMo[]){
// Khởi tạo con trỏ nút để duyệt danh sách
    Node *pNDT;
    
// Duyệt qua danh sách
    for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
// Kiểm tra xem quyMo của nút hiện tại có khớp với quyMo đầu vào không
        if (strcmp(pNDT->info.quyMo,quyMo)==0){
// Nếu trùng khớp, xuất thông tin của nút
            xuatNDT(pNDT->info);
        }
}

void Sapxepdiachi(List &Q){
	Node *pNDT, *q;
	NGUOIDONGTHUE tg;
// lặp qua danh sách để tìm chỗ không khớp
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	   for (q=pNDT->next;q!=NULL;q=q->next)
	     if (strcmp(pNDT->info.diaChi, q->info.diaChi)>0)
	       {
// hoán đổi các phần tử nếu tìm thấy không khớp
	       	tg=pNDT->info;
	      	pNDT->info=q->info;
	      	q->info=tg;
		   } 
// in danh sách cập nhật
	xuatDSNDT(Q); 
}

//xoa theo ma dong thue

void Remove(List &Q, int ma)
{
    Node *pNDT = Q.Head, *q = NULL; // con trỏ tới nút hiện tại, nút trước đó
    while(pNDT != NULL) // lặp qua danh sách
    {
        if(pNDT->info.maNguoiDT == ma) break; // ngắt nếu tìm thấy nút
        q = pNDT; // cập nhật nút trước đó
        pNDT = pNDT->next; // di chuyển tới nút tiếp theo
    }
    if(pNDT == NULL) cout<<"Khong tim thay ma"<<endl; // không tìm thấy
    if(q != NULL) // nếu không phải nút đầu tiên
    {
        if(q == Q.Tail) Q.Tail = q;// cập nhật đuôi
        q->next = pNDT->next; // bỏ qua nút cần xóa
        delete pNDT; // giải phóng bộ nhớ
    }
    else // nếu nút đầu tiên
    {
        Q.Head = pNDT->next; // cập nhật đầu
        if(Q.Head == NULL) Q.Head = NULL; // đầu trở thành null nếu trống
    }
    cout<<"Xoa thanh cong"<<endl; 
}


//cho biet Cong ty co dia chi tai x
void TimDiaChi(List &Q, char x[])
{
// Con trỏ duyệt danh sách
    Node*pNDT;
    
// Tiêu đề đầu ra
    cout<<"Danh sach cong ty co dia chi "<<x<<" la:"<<endl;
    
// Duyệt qua danh sách
    for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
    {
// Nếu địa chỉ trùng với địa chỉ đã cho
        if (strcmp(pNDT->info.diaChi,x)==0)
        {
// Xuất thông tin chi tiết về công ty
            xuatNDT(pNDT->info);
        }
    }
    
// Chân trang đầu ra
    cout<<endl;
}


void DienTichMax(List &Q){
 // Con trỏ duyệt danh sách
    Node *pNDT;
    
// Khởi tạo dienTich tối đa
    float max = -1;
    
// Lặp qua danh sách
    for(pNDT = Q.Head; pNDT != NULL; pNDT = pNDT->next)
// Cập nhật max nếu dienTich hiện tại lớn hơn
        if(max < pNDT->info.dienTich)
            max = pNDT->info.dienTich;
    
// Lặp lại danh sách một lần nữa
    for(pNDT = Q.Head; pNDT != NULL; pNDT = pNDT->next)
// Nếu dienTich hiện tại bằng max, in nút
        if(pNDT->info.dienTich == max)
            xuatNDT(pNDT->info);
}

void Sua(List &Q) {
// Lặp qua danh sách để tìm nút cần cập nhật
    Node *pNDT, *qNDT, *m;
    NGUOIDONGTHUE x;
    int maNDT;
    cout << "Nhap ma nguoi dong thue can sua: "; cin >> maNDT;
    for (pNDT = Q.Head; pNDT != NULL; pNDT = pNDT->next)
        if (pNDT->info.maNguoiDT == maNDT) {
            qNDT = pNDT;
        }
// Lặp lại lần nữa để tìm nút trước đó của nút cần cập nhật
    for (pNDT = Q.Head; pNDT != NULL; pNDT = pNDT->next)
        if (pNDT->next == qNDT) {
            m = pNDT;
        }
// Cập nhật nút
    nhapNDT(x);
    Node *q = getNode(x);
    if (m->next == NULL) {
        Q.Tail->next = q;
        Q.Tail = q;
    } else {
        Node *h = getNode(q->info);
        Node *tg = m->next;
        h->next = tg;
        m->next = h;
    }
// Xóa nút cũ khỏi danh sách
    Remove(Q, maNDT);
// In danh sách đã cập nhật
    xuatDSNDT(Q);
}



void chenphantusauma(List &Q){
	Node *p, *q;
	int maChen,dem=0;
	NGUOIDONGTHUE x;
	cout<<"Nhap ma can chen: "; cin>>maChen;
	for(p=Q.Head;p!=NULL;p=p->next)
			if(p->info.maNguoiDT==maChen){
			dem++;
			nhapNDT(x);
			q=getNode(x);
			if(p->next==NULL){
				Q.Tail->next=q;
				Q.Tail=q;
			}else{
				Node *h=getNode(q->info);
				Node *k=p->next;
				h->next=k;
				p->next=h;
			}
		}
	if(dem==0) cout<<"Khong tim thay ma"<<endl;
	xuatDSNDT(Q);
	
}


//Luu file
void Luufile(FILE *f, List &Q, char *name)
{
	// Open file with given name in read/write mode
	// Mở file có tên ở chế độ đọc/ghi
	f=fopen(name,"w+b");

	// Calculate the number of nodes in the list
	// Tính số lượng nút trong danh sách
	int n=0;
	Node *pNDT;
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next)
	{
	n=n+1;
	}

	 // Write the number of nodes to the file
	 // Ghi số nút vào file
	fwrite(&n,sizeof(int),1,f);

	// Write the information of each node to the file
	// Ghi thông tin của từng nút vào file
	for(pNDT=Q.Head;pNDT!=NULL;pNDT=pNDT->next){
	fwrite(&pNDT->info,sizeof(NGUOIDONGTHUE),1,f);
	}
	
	// Close the file
	fclose(f);

	// Display a message indicating successful file write
	cout<<"Ghi file thanh cong"<<endl;
}


void DocFile(FILE *f, List &Q, char *name)
{
    NGUOIDONGTHUE x;
    int i,n;
    Node *pNDT;
    KhoiTao(Q);

    f=fopen(name,"r+b"); // Open file
    if(f==NULL) // If file open failed
    {
        cout<<"Mo tep khong thanh cong"<<endl; // Display error message
        return;
    }

    cout<<"Bat dau doc file"<<endl; // Start reading file
    fread(&n,sizeof(int),1,f); // Read number of records

    for(i=0;i<n;i++)
    {
        fread(&x,sizeof(NGUOIDONGTHUE),1,f); // Read a record
        pNDT=getNode(x); // Create a node with record data
        insertLast(Q,pNDT); // Add node to list
    }

    fclose(f); // Close file
    cout<<"Doc file thanh cong"<<endl; // Display success message
    xuatDSNDT(Q); // Output list data
}

// //===Quan Ly Phieu Thu Thue(Danh sach lien ket doi)===

// // using namespace std;
// struct phieuthu {
// 	int mapt;
// 	string thoigian, nguoilap, hotennguoinop;
// 	float tongtien, sotiengiam, sotiencandong;
	
// };


// struct NodePT{
// 	phieuthu info;
// 	struct NodePT*next; 
// 	struct NodePT*prev;
// };


// struct LISTPT{
// 	NodePT*Head;
// 	NodePT*Tail;
// };


// LISTPT PT;
// void khoitaoPT ( LISTPT & PT )
// {
// 	PT.Head = NULL;
// 	PT.Tail = NULL;
// }

// NodePT * GetNode( phieuthu x  )
// {
// 	NodePT *p;
// 	p = new NodePT();
// 	if (p == NULL)
// {
// 	cout<<("Ko du bo nho");
// 	exit(1);
// }
// 	p -> info = x;
// 	p -> next = NULL;
// 	p -> prev = NULL;
// 	return p;
// } 


// void chencuoipt( LISTPT & PT, NodePT *p )
// {
// if ( PT.Head == NULL ) //nêu danh sách rông
// {
// PT.Head = p;
// PT.Tail = PT.Head;
// }
// else //danh sách không rông
// {
// PT.Tail->next=p;
// p->prev=PT.Tail;
// PT.Tail=p;
// }
// }
// void nhappt ( phieuthu &x){
// 	cout<<"\nma phieu thu: ";
// 	cin>>x.mapt;
// 	cout<<"\nho ten nguoi nop: ";
// 	cin.ignore();
// 	getline(cin,x.hotennguoinop);
// 	cout<<"\nthoi gian lap: ";
// 	getline(cin, x.thoigian);
// 	cout<<"\nnhap tong tien: ";
// 	cin>>x.tongtien;
// 	cout<<"\ntien giam tru: ";
// 	cin>>x.sotiengiam;
// 	x.sotiencandong= x.tongtien - x.sotiengiam;
	
// }

// void nhapdspt ( LISTPT & PT){
// 	int n;
// 	NodePT * p;
// 	phieuthu x;
// 	cout <<" nhap so phieu thu: "; cin>>n;
// 	for (int i=1 ; i<=n ; i++)
// 	{
// 		nhappt (x);
// 		p = GetNode(x); 
// 		chencuoipt( PT, p);
// 		}
		
// }


// void xuatpt ( phieuthu x){
// 	cout<<"\n"<<setw(5) << x.mapt;
// 	cout<<setw(15)<< x.hotennguoinop;
// 	cout<<setw(15)<< x.thoigian;
// 	cout<<setw(15)<< x.tongtien;
// 	cout<<setw(17)<< x.sotiengiam;
// 	cout<<setw(17)<< x.sotiencandong;
// }


// void xuatdspt ( LISTPT & PT){
// 	NodePT *p;
// 	cout<<"\n ds phieu thu hien co: \n";
// 	cout<<"\n"<<setw(8) << "ma pt";
// 	cout<<setw(20)<< "ho ten nguoi dong";
// 	cout<<setw(15)<< "thoi gian";
// 	cout<<setw(15)<< "tong tien";
// 	cout<<setw(17)<< "so tien giam";
// 	cout<<setw(17)<< "so tien can dong";
// 	for ( NodePT *p = PT.Head; p!= NULL;p = p->next)
// 	xuatpt( p->info);	
// }
// NodePT * timmapt ( LISTPT &PT, int mpt ){
// 	NodePT *p;
// 	for (p=PT.Head; p!=NULL; p=p->next)
// 	if (p->info.mapt == mpt)
// 	break;
// 	return p;
// }
// void sapxeppt(LISTPT PT){
// 	NodePT *p;
// 	NodePT *q;
// 	phieuthu tg;
// 	cout<<"\nsap xep theo so tien can dong";
// 	for(p = PT.Head; p!=NULL; p=p->next)
// 	for(q=p->next ; q!=NULL ; q=q->next){
// 		if(p->info.sotiencandong<q->info.sotiencandong)
// 		{
// 			tg=p->info;
// 			p->info=q->info;
// 			q->info=tg;
// 		}
// 	}
// 	xuatdspt(PT);	
// }
// void luuf(LISTPT PT){
// 	FILE *f;
// 	char filename[20];
// 	cout<<"Nhap ten FILE: ";fflush(stdin);gets(filename);
// 	f=fopen(filename,"w+b");
// 	for (NodePT *p= PT.Head; p != NULL; p = p->next){
// 		fwrite(&p->info,sizeof(phieuthu),1,f);
// }
// 			fclose(f);
// 	FILE *t;
// 	t=fopen("Ten FILE","a+b");
// 	fwrite(&filename,sizeof(filename),1,t);
// 	cout<<"Da luu vao: "<<filename<<endl;
// 	fclose(t);


// }
// void docf(LISTPT PT){
// 	khoitaoPT(PT);
// 	FILE *f;
// 	phieuthu x;
// 	char filename[20];
// 	NodePT*p;
// 	cout<<"Mo file:\nCac FILE da luu:"<<endl;
// 	char Ten[20];
// 	FILE *t;
// 	int i=0;
// 	t=fopen("Ten FILE","r+b");
// while(true)
//  {
//  if(t == NULL){ fclose(t);
// break; 
// }
//  	fread(&Ten ,sizeof(Ten),1,t);
//  	if(feof(t))break;
//  	i++;
//  	cout<<"File "<<i<<": "<<Ten<<endl;
//  	}
//  	fclose(t);
// 	cout<<"Nhap ten FILE muon mo: ";fflush(stdin);gets(filename);
// 	f=fopen(filename,"r+b");
// if(f == NULL)
//  {
// 	 cout<<"\nLoi mo tep";
// 	 return;
//  	}
//  	while(true)
//  	{
//  	fread(&x ,sizeof(phieuthu),1,f);
//  	if(feof(f))break;
//  	p=GetNode(x);
//  	chencuoipt(PT,p);
//  	}

//  while(!feof(f));
 
//  	fclose(f);
//  	cout<<"Danh sach trong file "<<filename<<" la:"<<endl;
//  	xuatdspt(PT);
// }


// void XoaNodeDau(LISTPT &PT){
// 	{
// 		if (PT.Head != NULL)
// 		{
// 			NodePT *p = PT.Head; 
// 			PT.Head = PT.Head->next;
// 			PT.Head->prev=NULL;
// 			delete p;
// 		}
// 		if(PT.Head==NULL)
// 		{
// 			khoitaoPT(PT);
// 		}
// 	}
// }

// void XoaNodeCuoi(LISTPT &PT){
// if (PT.Head->next == NULL)
// {
// XoaNodeDau(PT);
// return;
// }
// for (NodePT *p = PT.Head; p != NULL; p = p->next)
// {
// if (p->next == PT.Tail)
// {
// delete PT.Tail;
// p->next = NULL; 
// PT.Tail = p; 
// }
// }
// }

// void XoaNodeCoKhoaBatKy (LISTPT &PT,int xoa ){
// 	 NodePT *p;
// 	p = timmapt (PT,xoa); //Tìm ki?m ph?n t? d? xóa
// 	if ( p == NULL ){
// 		cout<<"Khong co phan tu"; exit(1);
// 	}
// else
// 	{
// if ( ( p == PT.Head ) && ( p == PT.Tail) )
// 			{ PT.Head = NULL; PT.Tail = NULL; }
// else if ( p == PT.Head ) PT.Head = p->next;
// else if ( p == PT.Tail ) PT.Tail = p -> prev; 
// else
// 	{
// 		p -> prev -> next = p -> next;
// 		p -> next -> prev = p -> prev;
// 	}
// 	free(p);
// 	}
// }



int main()
{
	List Q;
	Node *pNDT;
	int k,chon,luachon,choose;
	KhoiTao(Q);
	FILE *f;
	// NodePT *p;
	// khoitaoPT(PT);
	char filename[20] = "nguoidongthue.txt" ;
	quay_ve_trang_chinh:
	Quay_ve_trang_chinh:
		
	do{
		cout<<"\t|1.Quan Ly Nguoi Dong Thue "<<endl;
		// cout<<"\t|2.Quan Ly Phieu Thu "<<endl;
		cout<<"\t|0.Thoat "<<endl;
		cout<<"Xin moi chon: "; cin>>luachon;
		switch(luachon)
		{
			case 1: {
						do{
						cout<<"\t|1.Nhap danh sach nguoi dong thue "<<endl;
						cout<<"\t|2.In danh sach nguoi dong thue "<<endl;
						cout<<"\t|3.Tim kiem theo ma nguoi dong thue "<<endl;
						cout<<"\t|4.Sap xep theo dien tich "<<endl;
						cout<<"\t|5.Xoa theo nguoi dong thue theo ma "<<endl;
						cout<<"\t|6.Tim dia chi "<<endl;
						cout<<"\t|7.Luu File "<<endl;
						cout<<"\t|8.Doc File "<<endl;
						cout<<"\t|9.Tim dien tich lon nhat "<<endl;
						cout<<"\t|10.Sua nguoi dong thue "<<endl;
						cout<<"\t|11.Chen nguoi dong thue sau ma nao do "<<endl;
						cout<<"\t|12.Danh sach theo quy mo "<<endl;
						cout<<"\t|13.Sap xep dia chi "<<endl;
						cout<<"\t|00.Thoat ve giao dien chinh "<<endl;
						cout<<"chon: "; cin>>chon;
						switch(chon)
						{
							case 1: NhapDSNDT(Q);
									Luufile(f,Q,filename); break;
							case 2: xuatDSNDT(Q); break;
							case 3:
							cout<<"Nhap ma nguoi dong thue k: "; cin>>k;
							pNDT=search(Q,k);
							if (pNDT==NULL)
							{
								cout<<"Khong tim thay"<<endl;
							}else
							{
								cout<<"Tim thay"<<endl;
								xuatNDT(pNDT->info);
							 } 
						     break;
							case 4: sapxeptheodientich(Q); xuatDSNDT(Q); 
									Luufile(f,Q,filename); break;
							case 5: int ma;
									cout<<"Nhap ma nguoi dong thue can xoa: "; cin>>ma;
									Remove(Q,ma); xuatDSNDT(Q); 
									Luufile(f,Q,filename); break;
							case 6: char x[20];
									fflush(stdin);
									cout<<"Nhap dia chi can tim x: "; gets(x);
									TimDiaChi(Q,x);
									break;
							case 7: Luufile(f,Q,filename); break;
							case 8: DocFile(f,Q,filename); break;
							case 9: DienTichMax(Q); break;
							case 10: Sua(Q);
								Luufile(f,Q,filename);
								 break;
							case 11: chenphantusauma(Q); 
								Luufile(f,Q,filename);
								break;
								
							case 12: 
							char quymo[12];
							fflush(stdin);
							cout<<"Nhap quy mo: "; gets(quymo);
							ThongKe(Q,quymo);
							break;
							case 13: Sapxepdiachi(Q); break;
							case 00: goto quay_ve_trang_chinh; //exit(0);
						
						}
						
					}while(chon!=0);
				break;
			}
			// case 2: {
			// 			do{
			// 			cout<<"\n 1,Nhap dspt";
			// 			cout<<"\n 2.In dspt";
			// 			cout<<"\n 3.Tim kiem ma pt: ";
			// 			cout<<"\n 4.sxpt theo thanh tien giam dan:";
			// 			cout<<"\n 5.Xoa phieu thu theo ma: ";
			// 			cout<<"\n 6 Xoa phieu thu dau tien: ";
			// 			cout<<"\n 7 Xoa phieu thu cuoi cung: ";
			// 			cout<<"\n 8.Luu file: ";
			// 			cout<<"\n 9.Doc file: ";
			// 			cout<<"\n 00 Thoat ve giao dien chinh. ";
			// 			cout<<"\n chon:";
			// 			cin>>choose;
			// 			switch(choose)
			// 			{
			// 				case 1: nhapdspt(PT); break;
			// 				case 2: xuatdspt(PT);break;
			// 				case 3:
			// 					{
			// 					cout<<"\n Nhap ma can tim";
			// 					cin>>k;
			// 					p= timmapt(PT, k);
			// 					if ( p== NULL)
			// 					cout<<"\n Khong tim thay ";
			// 					else {
			// 						cout<<"\n pt can tim la";
			// 						cout<<"\n"<<setw(10) << "ma pt";
			// 						cout<<setw(10)<< "Ho ten nguoi dong";
			// 						cout<<setw(10)<< "Thoi gian";
			// 						cout<<setw(10)<< "Tong tien";
			// 						cout<<setw(10)<< "So tien giam";
			// 						cout<<setw(10)<< "So tien can dong";
			// 						xuatpt (p->info);
									
			// 					}
			// 					}break;
			// 					case 4: 
			// 					{
			// 					cout<<"Danh sach pt da sap xep:";
			// 					sapxeppt(PT);
			// 					cout<<"\n";
			// 					}break;
								
			// 					case 5: 
			// 					int xoa;
			// 					cout<<"Nhap ma can xoa";
			// 					cin>>xoa;
			// 					XoaNodeCoKhoaBatKy(PT,xoa);
			// 					cout<<"Danh sach sau khi xoa:";
			// 					xuatdspt(PT);
			// 					break;
								
			// 					case 6: {
			// 					XoaNodeDau(PT);
			// 					cout<<"Danh sach sau khi xoa phan tu dau tien: \n";
			// 					xuatdspt(PT);
			// 					}
			// 					break;
								
			// 					case 7:{
			// 						XoaNodeCuoi(PT);
			// 						cout<<"Danh sach sau khi xoa phan tu cuoi cung:\n";
			// 						xuatdspt(PT);
			// 						break;
			// 					}
								
			// 					case 8:{
			// 						luuf( PT);
			// 					return 0; }break;
							
			// 					case 9: {
			// 						docf( PT );return 0; }break;
			// 				 	case 00 : goto Quay_ve_trang_chinh; //exit(0);
							 
							
			// 			}
			// 		}
			// 		while (choose!=0);
			// 					break;
			// 				}
			case 0: exit(0);
		}
	}while(luachon!=0);
}
