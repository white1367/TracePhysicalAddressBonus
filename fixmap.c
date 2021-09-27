#include <linux/mm.h>
#include <linux/highmem.h>
#include <asm/fixmap.h>
#include <linux/module.h>
#include <linux/kernel.h>


int start(void){
    
    
    unsigned long kmap_begin_addr = fix_to_virt(3);
    unsigned long kmap_end_addr = fix_to_virt(FIX_KMAP_END);
    printk("FIX_KMAP_BEGIN=%d\n", FIX_KMAP_BEGIN);
    printk("FIX_KMAP_END=%d\n", FIX_KMAP_END);
    printk("FIX_KMAP_BEGIN virtual address=0x%lx\n",kmap_begin_addr);
    printk("FIX_KMAP_END virtual address=0x%lx\n",kmap_end_addr);
    printk("0x%lx\n", kmap_begin_addr-PAGE_OFFSET);
    set_fixmap(3, kmap_begin_addr-PAGE_OFFSET);
    return 0;
}

void cleanup(void){
    printk(KERN_INFO " Inside cleanup_module\n");
}

MODULE_LICENSE("GPL");   
module_init(start);
module_exit(cleanup);
