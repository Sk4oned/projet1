#ifndef MEMENTO_H
#define MEMENTO_H

class Memento<t>
{
    T state;

    public T GetState()
    {
        return state;
    }

    public void SetState(T state)
    {
        this.state = state;
    }
}

class Originator<t>
{
    T state;

    public:

    Memento<t> CreateMemento()
    {
        Memento<t> m = new Memento<t>();
        m.SetState(state);
        return m;
    }


    public void SetMemento(Memento<t> m)
    {
        state = m.GetState();
    }

    public void SetState(T state)
    {
        this.state = state;
    }

    public void ShowState()
    {
        Console.WriteLine(state.ToString());
    }
}


class Caretaker<t>
{

    private static List<memento><t>> mementoList = new List<memento><t>>();

    void SaveState(Originator<t> orig)
    {
        mementoList.Add(orig.CreateMemento());
    }

    void RestoreState(Originator<t> orig, int stateNumber)
    {
        orig.SetMemento(mementoList[stateNumber]);
    }
}

#endif // MEMENTO_H
