#!/bin/python3

import os

def email_template_fill(template, subject, variables):
    # [company, name, email] = variables
    [company, email] = variables
    # template = template.replace("<<Name>>", name)
    template = template.replace("<<Company name>>", company)

    email_line = email + '\n'
    subject = subject.replace("<<Company name>>", company)

    template = email + '\n' + subject + '\n' + template + '\n\n\n'

    return template

# template = """Dear <<Name>>,
# 
#            I hope the new year has treated you well so far! My name is Justin Ting, one of the Industry Liaisons for SUITS for 2016. I am reaching out to see what sort of partnership <<Company name>> would like with SUITS this year in engaging with the IT/Computer Science student body at the University of Sydney.
# 
#            Our prospectus for 2016 has three tiers - Bronze, Silver, and Gold level packages, with further details of each in the document attached to this email. 
# 
#            In addition, the University of Sydney's Orientation Week is coming up soon (running from February 22-26 inclusive) - if you would like to have <<Company name>> merchandise available for students at the SUITS stall during the week, we would be happy to help distribute those as well. These would need to be sent to the university by February 19th (Friday) for us to have enough time to organise the O-week bags. I will provide a mailing address if this is something you would be interested in.
# 
#            Please feel free to contact me with further questions via this email, or my mobile at 0424 751 665. 
# 
#            Kind Regards,"""
# 
# subject = "Re: Sydney University IT Society (SUITS), <<Company name>> Partnership 2016"

template = """
Dear Sir/Madam,

My name is Justin Ting, one of the Industry Liaisons for the Sydney University IT Society (SUITS for 2016. Our Orientation Week is coming up, where we run stalls for incoming and existing students in the IT area (computer science, software engineering, etc.) alike.

We also provide goodie bags at these events for students with sponsored, branded merchandise - I was wondering whether <<Company name>> would be interested in providing such merchandise? As our orientation week starts at the University February 22nd, these would need to arrive at the university by the 19th of February (Friday) to allow us enough time to pack/organise everything into bags.

Thank you for your time.

Kind Regards,
"""
subject = "Re: Sydney University IT Society (SUITS) O-Week <<Company name>> Merchandise"

os.remove('./templated_emails.txt')

with open('./names_emails_comapnies.txt') as f:
    content = f.readlines()
    
for item_set in content:
    company_items = item_set.strip().split('\t\t')
    templated = email_template_fill(template, subject, company_items)
    fo = open("templated_emails.txt", "a")
    fo.write(templated)
    fo.close()

