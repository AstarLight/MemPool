#ifndef __MEMPOOL_H__
#define __MEMPOOL_H__

#define DEBUG_ON 0
#define LOG(fmt,...) do{ if(DEBUG_ON)  printf(fmt,##__VA_ARGS__); }while(0)

typedef struct chunk_hdr_s chunk_hdr_t;

typedef struct chunk_hdr_s
{
	int chunk_id;
	bool used_flag;
	chunk_hdr_t* pBusyNext;
	chunk_hdr_t* pFreeNext;
}chunk_hdr_t;



class MemPool
{
public:
	MemPool(unsigned long pool_size = 10*1024*1024, int chunk_size = 256);  //Ĭ��MemPool�ܴ�С10MB��һ��chunk��СΪ512bytes,һ��20480��

	~MemPool();

	 void* AllocMem(unsigned long Memsize);

	 int DestroyMemPool();

	 void MemPool_info_dump();

	 int EnlargeMemPoolSize(int add_size);

	 int GetBusyLinkListLength();

	 int GetFreeLinkListLength();

	 int ReleaseMem(void* p);

	 void BusyLinkList_dump();

	 void FreeLinkList_dump();

private:
	unsigned long PoolSize;
	int ChunkSize;
	int DataSize;  //��ȥͷ����ʣ���data�����С��hdr��СΪ16bytes
	int TotalChunkNum;
	unsigned long FreeMemSize;
	unsigned long UsedMemSize;
	int Alloced_Chunk_Count;
	int data_offset;
	int BusyLinkListLen;
	int FreeLinkListLen;

	chunk_hdr_t* pMemPool_Start;
	chunk_hdr_t* pBusyLinkListHead;
	chunk_hdr_t* pFreeLinkListHead;
	chunk_hdr_t* pFreeLinkListTail;
	chunk_hdr_t* pBusyLinkListTail;

};



#endif
