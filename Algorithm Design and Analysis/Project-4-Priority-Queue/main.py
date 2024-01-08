import heapq
import random
import datetime

class Job:
    def __init__(self, job_num, job_name, submitter, submission_date, priority):
        self.job_num = job_num
        self.job_name = job_name
        self.submitter = submitter
        self.submission_date = submission_date
        self.priority = priority

    def __lt__(self, other):
        return self.priority < other.priority

class PriorityQueue:
    def __init__(self):
        self.jobs = []
        heapq.heapify(self.jobs)

    # Add jobs to queue w/o heapifying
    def add_job(self, job):
        heapq.heappush(self.jobs, job)
      
    def insert_job(self, job):
        heapq.heappush(self.jobs, job)
        heapq.heapify(self.jobs)
      
    def delete_job(self):
        if not self.is_empty():
            return heapq.heappop(self.jobs)
            heapq.heapify(self.jobs)
        else:
            return None

    def is_empty(self):
        return len(self.jobs) == 0

def generate_job(num):
    job_num = num
    job_name = f"Job{num}"
    submitter = f"Submitter{num}"
    submission_date = datetime.datetime.now()
    priority = random.randint(1, 25)
    return Job(job_num, job_name, submitter, submission_date, priority)

def display_queue(queue, queue_name):
    print(f"{queue_name}:")
    print("Job#\tName\tSubmitter\t\tPriority\tSubmission Date")
    for job in queue.jobs:
        print(job.job_num, "\t\t", job.job_name,"\t", job.submitter, "\t", job.priority, "\t\t\t", job.submission_date)
    print()

def main():
    wait_queue = PriorityQueue()
    ready_queue = PriorityQueue()

    # Add m jobs into the Wait Queue
    m = random.randint(11, 14)
    for num in range(1, m + 1):
        job = generate_job(num)
        wait_queue.add_job(job)

    print("BEFORE HEAPIFYING")
    display_queue(wait_queue, "Wait Queue")

    # Heapify the Wait Queue
    heapq.heapify(wait_queue.jobs)

    print("AFTER HEAPIFYING")
    display_queue(wait_queue, "Wait Queue")

    # Move highest priority job from Wait Queue to Ready Queue 5 times
    for _ in range(5):
        if not wait_queue.is_empty():
            job = wait_queue.delete_job()
            ready_queue.insert_job(job)

    # Display both queues after 5 moves
    print("AFTER 5 MOVES FROM WAIT TO READY")
    display_queue(wait_queue, "Wait Queue")
    display_queue(ready_queue, "Ready Queue")

    # Delete 3 jobs from Ready Queue
    for _ in range(3):
        if not ready_queue.is_empty():
            ready_queue.delete_job()

    # Display Ready Queue after deletions
    print("AFTER DELETING 3 FROM READY")
    display_queue(ready_queue, "Ready Queue")

    # Add 3 more jobs to Wait Queue
    for num in range(m + 1, m + 4):
        job = generate_job(num)
        wait_queue.insert_job(job)

    # Move 4 jobs from Wait Queue to Ready Queue
    for _ in range(4):
        if not wait_queue.is_empty():
            job = wait_queue.delete_job()
            ready_queue.insert_job(job)

    # Delete 2 jobs from Ready Queue
    for _ in range(2):
        if not ready_queue.is_empty():
            ready_queue.delete_job()

    # Display both queues after these operations
    print("AFTER ADDING 3 TO WAIT, MOVING 4 FROM WAIT TO READY, AND DELETING 2 FROM READY")
    display_queue(wait_queue, "Wait Queue")
    display_queue(ready_queue, "Ready Queue")

    # Change priority of 3 jobs in the Wait Queue
    # Per instructions, the queue is heapified after each change, so some jobs may change priority more than once, however a total of three priority changes will occur. 
    for _ in range(3):
      if not wait_queue.is_empty():
          jerb = wait_queue.delete_job()
          if jerb.priority < 25:
              jerb.priority = jerb.priority + 1
          else:
              jerb.priority = 1
          wait_queue.insert_job(jerb)

    # Display Wait Queue after changing priorities
    print("AFTER CHANGING PRIORITY OF 3")
    print("Note: One or more of the three priority changes may be the same job changing priority more than once.")
    display_queue(wait_queue, "Wait Queue")

    # Continue deleting until both queues are empty
    while not wait_queue.is_empty():
        wait_queue.delete_job()
    while not ready_queue.is_empty():
        ready_queue.delete_job()

    print("WAIT AND READY ARE EMPTY")

if __name__ == "__main__":
    main()
