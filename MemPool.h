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
	MemPool(unsigned long pool_size = 10*1024*1024, int chunk_size = 256);  //默认MemPool总大小10MB，一个chunk大小为512bytes,一共20480块

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
	int DataSize;  //除去头部，剩余的data区域大小。hdr大小为16bytes
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
