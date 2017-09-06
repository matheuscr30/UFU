#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/pid.h>
#include <linux/sched.h>

asmlinkage long sys_projetopid(int pid)
{	
	struct task_struct *task = find_task_by_vpid(pid);
	//task_struct *task = pid_task(find_vpid(pid), PIDTYPE_PID);
	
	if(task != NULL){
		printk("Processo %d existe\n", pid);

		long int status = task->state;
		printk("Status: %ld\n", status);
		
		if(task->state == TASK_RUNNING){   //Running
			task->state = TASK_INTERRUPTIBLE;
			schedule();
			printk("Mudou o status para: Stopped\n");
		}
		else if(task->state == TASK_INTERRUPTIBLE){   //Stopped
			wake_up_process(task);
			printk("Mudou o status para: Running\n");
		}		
	}
	else{
		printk("Processo %d nao existe\n", pid);
		return -1;
	}

	return 0;
}
