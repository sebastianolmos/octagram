class point
{
    private:
        int mX;
    public:
        point();
        point(int x){
            this->mX = x;
        }
        int getX(){
            return this->mX;
        }

};