# Add config files
RUN mkdir /etc/ssepush /var/log/ssepush
ADD config.template.xml /etc/ssepush/
ADD logback.template.properties /etc/ssepush/
ADD server.template.xml /

# Fix permission
RUN chmod -R ugo+rwx /etc/ssepush /var/log/ssepush

# Add startup script
ADD bootstrap.sh /
RUN chmod +x /bootstrap.sh

# Volume options
VOLUME ["/opt/tomcat/logs", "/var/log/ssepush"]
 
# Open Tomcat port
EXPOSE 8080

CMD ["/bootstrap.sh"]
