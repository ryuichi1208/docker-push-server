#include <linux/module.h>       /* MODULE, THIS_MODULE */
#include <linux/moduleparam.h>
#include <linux/kernel.h>       /* printk() */
#include <linux/errno.h>        /* error codes */
#include <linux/list.h>         /* list_*() */
#include <linux/slab.h>         /* kmalloc() */

MODULE_AUTHOR("kuredev");
MODULE_LICENSE("Dual BSD/GPL");

struct kurest
{
        int no;
        struct list_head list_head_;
};

struct kurest data1 = {
        .no = -1,
};

static int kure_init(void)
{
        printk(KERN_ALERT "Listtest init\n");
        struct kurest *data2, *data3;
        struct list_head *ptr;
        struct kurest *entry;
        INIT_LIST_HEAD(&data1.list_head_);

        data2 = kmalloc(sizeof(struct kurest), GFP_KERNEL);
        data2->no = 2;
        list_add(&data2->list_head_, &data1.list_head_);

        data3 = kmalloc(sizeof(struct kurest), GFP_KERNEL);
        data3->no = 3;
        list_add(&data3->list_head_, &data1.list_head_);

        list_for_each(ptr, &data1.list_head_){
                 entry = list_entry(ptr, struct kurest, list_head_);
                 printk("no: %d\n", entry->no);
        }

        return 0;
}


static void kure_exit(void)
{
        printk(KERN_ALERT "Listtest exit\n");
}

module_init(kure_init);
module_exit(kure_exit);
