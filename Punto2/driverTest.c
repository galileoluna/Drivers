#include <linux/module.h> 
#include <linux/string.h> 
#include <linux/fs.h> 
#include <linux/uaccess.h>



static char msg[100] ={0}; 
static short readPos = 0; 
static int times = 0;

static int device_open (struct inode *, struct file *);
static int device_release (struct inode *, struct file *);
static ssize_t device_read (struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);




static struct file_operations fops = {
  
  .read = device_read,
  .open = device_open,
  .write = device_write,
  .release = device_release,

};

int init_module(void) {
  
  int t = register_chrdev(,1 "driverTest", &fops) ; 

  if (t < 0) 
    printk(KERN_ALERT "No se pudo registrar el device .. \n");
  else 
    printk(KERN_ALERT "Se registro el Device ... \n");
  return t;

}

void cleanup_module(void){ 
  
  unregister_chrdev(91,"driverTest");

}


static int device_open (struct inode *inod, struct file *fil) { 
  
  times++; 
  printk(KERN_ALERT "El device fue abierto %d veces .... \n", times); 
  return 0;
  
}

static ssize_t device_read (struct file *filp, char *buff, size_t len, loff_t *off) {

  short count = 0;
  while (len && (msg[readPos] != 0) ) { 
    put_user(msg[readPos], buff++);
    count++; 
    len--; 
    readPos++;
  }
  return count;
}

static ssize_t device_write (struct file *filp,const char *buff, size_t len, loff_t *off) {


  short ind = len - 1;
  short count = 0; 
  memset(msg, 0, 100);
  readPos = 0;
  while(len > 0) {
    msg[count++] = buff[ind--]; 
    len--;
  }

  return count; 

}


static int device_release(struct inode *inod, struct file *fil) {
  
  printk(KERN_ALERT "Se cerro el Device\n"); 
  return 0; 

}



MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Device Driver");
MODULE_AUTHOR("Galileo Luna ");