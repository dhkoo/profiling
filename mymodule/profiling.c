#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/calclock.h>

extern int xfs_file_enabled, filemap_enabled, filemap_enabled_2;

extern unsigned long long calclock_time[NUMCORE], calclock_count[NUMCORE];

extern unsigned long long xfs_file_buffered_aio_write_time[NUMCORE], xfs_file_buffered_aio_write_count[NUMCORE];
extern unsigned long long xfs_rw_ilock_time[NUMCORE], xfs_rw_ilock_count[NUMCORE];
extern unsigned long long generic_file_buffered_write_time[NUMCORE], generic_file_buffered_write_count[NUMCORE];
extern unsigned long long xfs_rw_iunlock_time[NUMCORE], xfs_rw_iunlock_count[NUMCORE];

extern unsigned long long generic_perform_write_time[NUMCORE], generic_perform_write_count[NUMCORE];
extern unsigned long long iov_iter_copy_from_user_atomic_time[NUMCORE], iov_iter_copy_from_user_atomic_count[NUMCORE];
extern unsigned long long write_begin_time[NUMCORE], write_begin_count[NUMCORE];
extern unsigned long long flush_dcache_page_time1[NUMCORE], flush_dcache_page_count1[NUMCORE];
extern unsigned long long pagefault_disable_time[NUMCORE], pagefault_disable_count[NUMCORE];
extern unsigned long long pagefault_enable_time[NUMCORE], pagefault_enable_count[NUMCORE];
extern unsigned long long flush_dcache_page_time2[NUMCORE], flush_dcache_page_count2[NUMCORE];
extern unsigned long long mark_page_accessed_time[NUMCORE], mark_page_accessed_count[NUMCORE];
extern unsigned long long write_end_time[NUMCORE], write_end_count[NUMCORE];
extern unsigned long long cond_resched_time[NUMCORE], cond_resched_count[NUMCORE];
extern unsigned long long iov_iter_advance_time[NUMCORE], iov_iter_advance_count[NUMCORE];
extern unsigned long long balance_dirty_pages_ratelimited_time[NUMCORE], balance_dirty_pages_ratelimited_count[NUMCORE];

static int __init init_dhkoo(void)
{
    int i;
    xfs_file_enabled = 1;
    filemap_enabled = 1;
    filemap_enabled_2 = 1;
    for (i=0; i<NUMCORE; i++){
        calclock_time[i] = 0; calclock_count[i] = 0;
        xfs_file_buffered_aio_write_time[i] = 0; xfs_file_buffered_aio_write_count[i] = 0;
        xfs_rw_ilock_time[i] = 0; xfs_rw_ilock_count[i] = 0;
        generic_file_buffered_write_time[i] = 0; generic_file_buffered_write_count[i] = 0;
        xfs_rw_iunlock_time[i] = 0; xfs_rw_iunlock_count[i] = 0;

        generic_perform_write_time[i] = 0; generic_perform_write_count[i] = 0;
        write_begin_time[i] = 0; write_begin_count[i] = 0;
        flush_dcache_page_time1[i] = 0; flush_dcache_page_count1[i] = 0;
        pagefault_disable_time[i] = 0; pagefault_disable_count[i] = 0;
        iov_iter_copy_from_user_atomic_time[i] = 0; iov_iter_copy_from_user_atomic_count[i] = 0;
        pagefault_enable_time[i] = 0; pagefault_enable_count[i] = 0;
        flush_dcache_page_time2[i] = 0; flush_dcache_page_count2[i] = 0;
        mark_page_accessed_time[i] = 0; mark_page_accessed_count[i] = 0;
        write_end_time[i] = 0; write_end_count[i] = 0;
        cond_resched_time[i] = 0; cond_resched_count[i] = 0;
        iov_iter_advance_time[i] = 0; iov_iter_advance_count[i] = 0;
        balance_dirty_pages_ratelimited_time[i] = 0; balance_dirty_pages_ratelimited_count[i] = 0;
    }
    printk("=====IO profiling=====\n");
    return 0;
}

static int __exit exit_dhkoo(void)
{
    xfs_file_enabled = 0;
    filemap_enabled = 0;
    //unsigned long long sum_time1=0, sum_count1=0, sum_time2=0, sum_count2=0, sum_time3=0, sum_count3=0, sum_time4=0, sum_count4=0, sum_time5=0, sum_count5=0, sum_time6=0, sum_count6=0, sum_time7=0, sum_count7=0, sum_time8=0, sum_count8=0, sum_time9=0, sum_count9=0, sum_time10=0, sum_count10=0, sum_time11=0, sum_count11=0, sum_time12=0, sum_count12=0, sum_time13=0, sum_count13=0, sum_time14=0, sum_count14=0, sum_time15=0, sum_count15=0, sum_time16=0, sum_count16=0, sum_time17=0, sum_count17=0;
    unsigned long long sum_time[17]={0,}, sum_count[17]={0,};
    int i;
    for (i=0; i<NUMCORE; i++){
       sum_time[0] += calclock_time[i]; sum_count[0] += calclock_count[i];
       sum_time[1] += xfs_file_buffered_aio_write_time[i]; sum_count[1] += xfs_file_buffered_aio_write_count[i];
       sum_time[2] += xfs_rw_ilock_time[i]; sum_count[2] += xfs_rw_ilock_count[i];
       sum_time[3] += generic_file_buffered_write_time[i]; sum_count[3] += generic_file_buffered_write_count[i];
       sum_time[4] += xfs_rw_iunlock_time[i]; sum_count[4] += xfs_rw_iunlock_count[i];
       sum_time[5] += generic_perform_write_time[i]; sum_count[5] += generic_perform_write_count[i];
       sum_time[6] += write_begin_time[i]; sum_count[6] += write_begin_count[i];
       sum_time[7] += flush_dcache_page_time1[i]; sum_count[7] += flush_dcache_page_count1[i];
       sum_time[8] += pagefault_disable_time[i]; sum_count[8] += pagefault_disable_count[i];
       sum_time[9] += iov_iter_copy_from_user_atomic_time[i]; sum_count[9] += iov_iter_copy_from_user_atomic_count[i];
       sum_time[10] += pagefault_enable_time[i]; sum_count[10] += pagefault_enable_count[i];
       sum_time[11] += flush_dcache_page_time2[i]; sum_count[11] += flush_dcache_page_count2[i];
       sum_time[12] += mark_page_accessed_time[i]; sum_count[12] += mark_page_accessed_count[i];
       sum_time[13] += write_end_time[i]; sum_count[13] += write_end_count[i];
       sum_time[14] += cond_resched_time[i]; sum_count[14] += cond_resched_count[i];
       sum_time[15] += iov_iter_advance_time[i]; sum_count[15] += iov_iter_advance_count[i];
       sum_time[16] += balance_dirty_pages_ratelimited_time[i]; sum_count[16] += balance_dirty_pages_ratelimited_count[i];
    }
    printk("calclock_time : %llu, calclock_count : %llu\n", sum_time[0], sum_count[0]);
    printk("xfs_file_buffered_aio_write_time : %llu, xfs_file_buffered_aio_write_count : %llu\n", sum_time[1], sum_count[1]);
    printk("xfs_rw_ilock_time : %llu, xfs_rw_ilock_count : %llu\n", sum_time[2], sum_count[2]);
    printk("generic_file_buffered_write_time : %llu, generic_file_buffered_write_count : %llu\n", sum_time[3], sum_count[3]);
    printk("xfs_rw_iunlock_time : %llu, xfs_rw_iunlock_count : %llu\n", sum_time[4], sum_count[4]);
    printk("======================\n");
    printk("generic_perform_write_time : %llu, generic_perform_write_count : %llu\n", sum_time[5], sum_count[5]);
    printk("write_begin_time : %llu, write_begin_count : %llu\n", sum_time[6], sum_count[6]);
    printk("flush_dcache_page_time1 : %llu, flush_dcache_page_count1 : %llu\n", sum_time[7], sum_count[7]);
    printk("pagefault_disable_time : %llu, pagefault_disable_count : %llu\n", sum_time[8], sum_count[8]);
    printk("iov_iter_copy_from_user_atomic_time : %llu, iov_iter_copy_from_user_atomic_count : %llu\n", sum_time[9], sum_count[9]);
    printk("pagefault_enable_time : %llu, pagefault_enable_count : %llu\n", sum_time[10], sum_count[10]);
    printk("flush_dcache_page_time2 : %llu, flush_dcache_page_count2 : %llu\n", sum_time[11], sum_count[11]); 
    printk("mark_page_accessed_time : %llu, mark_page_accessed_count : %llu\n", sum_time[12], sum_count[12]);
    printk("write_end_time : %llu, write_end_count : %llu\n", sum_time[13], sum_count[13]);
    printk("cond_resched_time : %llu, cond_resched_count : %llu\n", sum_time[14], sum_count[14]);
    printk("iov_iter_advance_time : %llu, iov_iter_advance_count : %llu\n", sum_time[15], sum_count[15]);
    printk("balance_dirty_pages_ratelimited_time : %llu, balance_dirty_pages_ratelimited_count : %llu\n", sum_time[16], sum_count[16]);
    return 0;
}

module_init(init_dhkoo);
module_exit(exit_dhkoo);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Donghun Koo");
MODULE_DESCRIPTION("For measuring the function time");
